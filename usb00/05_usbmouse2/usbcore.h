#ifndef __USBCORE_H__
#define __USBCORE_H__

#include "PDIUSBD12.H"

void delayms(unsigned short);

#define CONNECT 1
#define DISCONNECT 0
void usb_set_bus(unsigned char);

void usb_interrupt_print(unsigned char);

#endif /* __USBCORE_H__ */