import usb.core
import usb.util

dev = usb.core.find(idVendor=0x04b4, idProduct=0x8613)
if dev is None:
    print("Device not found")
else:
    for cfg in dev:
        print("Configuration:", cfg.bConfigurationValue)
        for intf in cfg:
            print(" Interface:", intf.bInterfaceNumber)
            for ep in intf:
                print("  Endpoint: 0x%02x, type: %s, max packet: %d" % (
                    ep.bEndpointAddress, usb.util.endpoint_type(ep.bmAttributes), ep.wMaxPacketSize))
