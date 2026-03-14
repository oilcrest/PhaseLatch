// Minimal USB descriptor set for FX2 streaming on EP6 IN bulk 512B
// Uses Cypress VID/PID placeholder (04B4:8613) - replace PID for production.

#include <stdint.h>
#include <fx2regs.h>
#include <fx2macros.h>
#include "config.h"

// Standard descriptor types
#define DT_DEVICE        0x01
#define DT_CONFIG        0x02
#define DT_STRING        0x03
#define DT_INTERFACE     0x04
#define DT_ENDPOINT      0x05

// Endpoint address
#define EP6_IN  0x86

// Device Descriptor (USB2.0, vendor specific class)
__code const uint8_t dev_dscr[] = {
    18,             // bLength
    DT_DEVICE,      // bDescriptorType
    0x00,0x02,      // bcdUSB 2.00
    0xFF,           // bDeviceClass (vendor)
    0x00,           // bDeviceSubClass
    0x00,           // bDeviceProtocol
    64,             // bMaxPacketSize0
    0xB4,0x04,      // idVendor 0x04B4 Cypress
    0x13,0x86,      // idProduct 0x8613
    0x00,0x01,      // bcdDevice 1.00
    1,              // iManufacturer
    2,              // iProduct
    0,              // iSerialNumber
    1               // bNumConfigurations
};

// Configuration Descriptor + Interface + Endpoint
__code const uint8_t cfg_dscr[] = {
    // Configuration
    9, DT_CONFIG,
    9+9+7,0x00,     // wTotalLength (configuration + interface + endpoint)
    1,              // bNumInterfaces
    1,              // bConfigurationValue
    0,              // iConfiguration
    0x80,           // bmAttributes (bus powered)
    50,             // bMaxPower (100mA)
    // Interface
    9, DT_INTERFACE,
    0,              // bInterfaceNumber
    0,              // bAlternateSetting
    1,              // bNumEndpoints (only EP8 IN)
    0xFF,           // bInterfaceClass (vendor)
    0x00,           // bInterfaceSubClass
    0x00,           // bInterfaceProtocol
    0,              // iInterface
    // Endpoint (Bulk IN EP6 512B)
    7, DT_ENDPOINT,
    EP6_IN,         // bEndpointAddress
    0x02,           // bmAttributes (Bulk)
    0x00,0x02,      // wMaxPacketSize = 512
    0               // bInterval (ignored for bulk)
};

// String descriptors (Unicode LE)
__code const uint8_t str0_dscr[] = { 4, DT_STRING, 0x09, 0x04 }; // LangID EN-US
__code const uint8_t str1_dscr[] = { 16, DT_STRING, 'P',0,'h',0,'a',0,'s',0,'e',0,'L',0,'m',0 }; // "PhaseLm"
__code const uint8_t str2_dscr[] = { 18, DT_STRING, 'F',0,'X',0,'2',0,' ',0,'S',0,'t',0,'r',0,'m',0 }; // "FX2 Strm"

// Descriptor table used by fx2lib's default GET_DESCRIPTOR hook (weak linkage)
__code const uint8_t* const dev_dscr_ptr   = dev_dscr;
__code const uint8_t* const cfg_dscr_ptr   = cfg_dscr;
__code const uint8_t* const highspd_dscr   = cfg_dscr; // same
__code const uint8_t* const fullspd_dscr   = cfg_dscr; // same (will be truncated logically to 64B packets by host if FS)
__code const uint8_t* const dev_qual_dscr  = 0;        // not providing device qualifier

// String table pointer list (fx2lib expects names)
__code const uint8_t* const string_dscrs[] = {
    str0_dscr,
    str1_dscr,
    str2_dscr
};

__code const uint8_t* const USBDSCR = dev_dscr;
