#ifndef __USBCORE_H__
#define __USBCORE_H__

#include "PDIUSBD12.H"

void delayms(unsigned short);

#define CONNECT 1
#define DISCONNECT 0
void usb_set_bus(unsigned char);

void usb_suspend(void);
void usb_reset(void);

#define SUSPEND_CHANGE (1 << 7)
#define BUS_RESET (1 << 6)
#define MAIN_IN_ENDPOINT (1 << 5)
#define MAIN_OUT_ENDPOINT (1 << 4)
#define ENDPOINT_1_IN (1 << 3)
#define ENDPOINT_1_OUT (1 << 2)
#define CONTROL_IN_ENDPOINT (1 << 1)
#define CONTROL_OUT_ENDPOINT (1 << 0)

void usb_endpoint0_in(void);
void usb_endpoint0_out(void);

#define GET_STATUS (0x00)
#define CLEAR_FEATURE (0x01)
#define SET_FEATURE (0x03)
#define SET_ADDRESS (0x05)
#define GET_DESCRIPTOR (0x06)
#define SET_DESCRIPTOR (0x07)
#define GET_CONFIGURATION (0x08)
#define SET_CONFIGURATION (0x09)

#define DEVICE_DESCRIPTOR (1)
#define CONFIGURATION_DESCRIPTOR (2)
#define STRING_DESCRIPTOR (3)
#define INTERFACE_DESCRIPTOR (4)
#define ENDPOINT_DESCRIPTOR (5)

#endif /* __USBCORE_H__ */