import usb.core
import usb.util

dev = usb.core.find(idVendor=0x04b4, idProduct=0x8613)
if dev is None:
    print("Device not found")
    exit(1)

dev.set_configuration()
cfg = dev.get_active_configuration()
intf = cfg[(0,1)]  # Interface 0, AltSetting 1
dev.set_interface_altsetting(interface=intf.bInterfaceNumber, alternate_setting=intf.bAlternateSetting)
usb.util.claim_interface(dev, intf.bInterfaceNumber)
ep = usb.util.find_descriptor(intf, bEndpointAddress=0x88)
if ep is None:
    print("Endpoint 0x88 not found in alt 1")
else:
    try:
        data = dev.read(ep.bEndpointAddress, ep.wMaxPacketSize, timeout=1000)
        print("Read succeeded, bytes:", len(data))
        print("First 16 bytes:", list(data[:16]))
    except usb.core.USBError as e:
        print("USBError:", e)