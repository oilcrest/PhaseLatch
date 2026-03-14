#!/usr/bin/env python3
"""
Simple PyUSB vendor-control test for FX2 firmware.

Uses firmware vendor commands in the 0xB0–0xBA range:
- 0xB1: GET CPUCS
- 0xB0: SET CPUCS (masked write: [mask, value])
- 0xB3: GET IFCONFIG
- 0xB8: GET EP6CS
- 0xB9: GET PINFLAGSAB
- 0xBA: GET PINFLAGSCD
"""
import sys
import usb.core
import usb.util
from usb.core import USBTimeoutError

VID = 0x04B4
PID = 0x8613

dev = usb.core.find(idVendor=VID, idProduct=PID)
if dev is None:
    raise SystemExit("FX2 device not found; ensure firmware is flashed and device is powered")

print('Found device: idVendor=0x%04x idProduct=0x%04x' % (VID, PID))
print('Device object:', dev)

# Try to set configuration
try:
    dev.set_configuration()
    print('Set configuration OK')
except Exception as e:
    print('set_configuration:', repr(e))

# Attempt to detach kernel driver (if any) and claim interface 0
cfg = None
try:
    cfg = dev.get_active_configuration()
    print('Active configuration:', cfg.bConfigurationValue)
    intf = cfg[(0, 0)]
    print('Found interface:', intf.bInterfaceNumber)
    if dev.is_kernel_driver_active(intf.bInterfaceNumber):
        try:
            dev.detach_kernel_driver(intf.bInterfaceNumber)
            print('Detached kernel driver from interface', intf.bInterfaceNumber)
        except Exception as e:
            print('Failed to detach kernel driver:', e)
    try:
        usb.util.claim_interface(dev, intf.bInterfaceNumber)
        print('Claimed interface', intf.bInterfaceNumber)
    except Exception as e:
        print('claim_interface failed (may be OK on macOS):', e)
except Exception as e:
    print('Could not get/claim interface info:', e)

def try_ctrl_transfer(request_type_list, request, data_or_length, timeout=5000):
    """Try a list of bmRequestType values until one succeeds."""
    last_exc = None
    for rt in request_type_list:
        try:
            if isinstance(data_or_length, int):
                d = dev.ctrl_transfer(rt, request, 0, 0, data_or_length, timeout=timeout)
            else:
                d = dev.ctrl_transfer(rt, request, 0, 0, data_or_length, timeout=timeout)
            return rt, d
        except Exception as e:
            last_exc = e
    raise last_exc

def get_byte(request, timeout=5000):
    """Generic GET for one byte from firmware via vendor IN request code."""
    rts = [0xC0, 0xC1, 0xC2]
    rt, data = try_ctrl_transfer(rts, request, 1, timeout=timeout)
    print('GET 0x%02x succeeded with bmRequestType=0x%02x' % (request, rt))
    return int(data[0])

def get_cpucs(timeout=5000):
    return get_byte(0xB1, timeout)

def get_ifconfig(timeout=5000):
    return get_byte(0xB3, timeout)

def get_ep6cs(timeout=5000):
    return get_byte(0xB8, timeout)

def get_pinflags_ab(timeout=5000):
    return get_byte(0xB9, timeout)

def get_pinflags_cd(timeout=5000):
    return get_byte(0xBA, timeout)

def get_ifconfig_snapshot(timeout=5000):
    return get_byte(0xBB, timeout)

try:
    print('CPUCS before:', hex(get_cpucs()))
except USBTimeoutError as e:
    print('Timeout reading CPUCS (no response). Is firmware running and handling vendor requests?')
    print('Error:', e)
    sys.exit(2)

def set_cpucs_masked(mask, value, timeout=5000):
    """Masked write to CPUCS via vendor OUT 0xB0: payload [mask, value]."""
    rts_out = [0x40, 0x41, 0x42]
    rt_out, _ = try_ctrl_transfer(rts_out, 0xB0, [mask & 0xFF, value & 0xFF], timeout=timeout)
    print('SET CPUCS masked (mask=0x%02x, value=0x%02x) via bmRequestType=0x%02x' % (mask, value, rt_out))

def set_ifconfig_masked(mask, value, timeout=5000):
    """Masked write to IFCONFIG via vendor OUT 0xB2: payload [mask, value]."""
    rts_out = [0x40, 0x41, 0x42]
    rt_out, _ = try_ctrl_transfer(rts_out, 0xB2, [mask & 0xFF, value & 0xFF], timeout=timeout)
    print('SET IFCONFIG masked (mask=0x%02x, value=0x%02x) via bmRequestType=0x%02x' % (mask, value, rt_out))

# Read diagnostics first to avoid aborting on CPUCS errors
try:
    print('IFCONFIG:', hex(get_ifconfig()))
    print('IFCONFIG snapshot (boot):', hex(get_ifconfig_snapshot()))
except Exception as e:
    print('Diagnostics GET failed (IFCONFIG):', e)

# Try toggling CLKOE (bit1), but continue on failure
try:
    before = get_cpucs()
    print('CPUCS before:', hex(before))
    set_cpucs_masked(0x02, before ^ 0x02)
    after = get_cpucs()
    print('CPUCS after toggle bit1:', hex(after))
except Exception as e:
    print('CPUCS SET failed:', e)

# Restore: read original and clear bit
orig = get_cpucs()
try:
    set_cpucs_masked(0x02, orig & ~0x02)
    print('Restored CPUCS to:', hex(get_cpucs()))
except Exception as e:
    print('Failed to restore CPUCS:', e)

try:
    # Try forcing IFCONFIG to 0xE3 and read back, but continue on failure
    try:
        set_ifconfig_masked(0xFF, 0xE3)
        print('IFCONFIG after set 0xE3:', hex(get_ifconfig()))
    except Exception as e:
        print('IFCONFIG SET failed:', e)
    print('EP6CS   :', hex(get_ep6cs()))
    print('PINFLAGSAB:', hex(get_pinflags_ab()))
    print('PINFLAGSCD:', hex(get_pinflags_cd()))
except Exception as e:
    print('Diagnostics GET failed (EP/flags):', e)

print('Vendor control test completed successfully')
