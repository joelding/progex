#include <stdio.h>
#include "usbcore.h"

unsigned char idata Buffer[16];

void delayms(unsigned short ms)
{
	unsigned short i, j;
	
	for (i = 0; i < ms; i++) {
		for (j = 0; j < 227; j++);
	}
}

#define NO_LAZYCLOCK (1 << 1)
#define CLOCK_ALWAYS_RUNNING (1 << 2)
#define INTERRUPT_ALL_ERRORS (1 << 3)
#define CONN_UPSTREAM_PULLUP (1 << 4)

#define SET_TO_ONE (1 << 6)
#define CLK_DIV_FACTOR (7) /* 48MHz/(7+1) = 6MHz */

/*
* s: 1, to connect; 0, to disconnect
*/
void usb_set_bus(unsigned char s)
{
	D12_write_cmd(ID_SET_MODE);
	
	if (s) {
		D12_write_byte(CONN_UPSTREAM_PULLUP | CLOCK_ALWAYS_RUNNING | NO_LAZYCLOCK);	
	} else {
		D12_write_byte(CLOCK_ALWAYS_RUNNING | NO_LAZYCLOCK);	
	}
	
	D12_write_byte(SET_TO_ONE | CLK_DIV_FACTOR);
	
	if (!s) {		
		printf("bus disconnects\n");
		delayms(1000);
	} else {
		printf("bus connects\n");
	}
}

void usb_suspend(void)
{
	printf("bus suspend change\n");
}

void usb_reset(void)
{
	printf("bus reset\n");
}

#define DATA_PHASE_TRANSFER_DIRECTION (1 << 7)
#define HOST_TO_DEV (0 << 7)
#define DEV_TO_HOST (1 << 7)
#define TYPE (0x3 << 5)
#define STANDARD (0 << 5)
#define CLASS (1 << 5)
#define VENDOR (2 << 5)

#define IDX_MAX_PACKET_SIZE 7
unsigned char *p_send_data;
unsigned short send_len;
unsigned char need_zero_packet;
unsigned char code dev_desc[18] = {
	18, /*	bLength: Size of the Descriptor in Bytes (18 bytes) */
	1, /*	bDescriptorType: Device Descriptor (0x01) */
	0x10,
	0x01, /* bcdUSB: USB Specification Number. USB 2.0 is reported as 0x0200, USB 1.1 as 0x0110 and USB 1.0 as 0x0100. */
	0, /* bDeviceClass: Class Code (Assigned by USB Org) */
	0, /* bDeviceSubClass: Subclass Code (Assigned by USB Org) */
	0, /* bDeviceProtocol: Protocol Code (Assigned by USB Org) */
	0x10, /* bMaxPacketSize: Maximum Packet Size for Zero Endpoint. Valid Sizes are 8, 16, 32, 64 */
	0x88, /* idVendor: Vendor ID (Assigned by USB Org) */
	0x88, 
	0x01, /* idProduct: Product ID (Assigned by Manufacturer) */
	0x00, 
	0x00, /* bcdDevice: Device Release Number 1.0 */
	0x01, 
	0x01, /* iManufacturer: Index of Manufacturer String Descriptor */
	0x02, /* iProduct: Index of Product String Descriptor */
	0x03, /* iSerialNumber: Index of Serial Number String Descriptor */
	0x01 /* bNumConfigurations: Number of Possible Configurations */
};

void usb_endpoint0_send_data(void)
{
	//printf("usb_ep0_send_data\n");
	
	if (send_len > dev_desc[IDX_MAX_PACKET_SIZE]) {
		D12_write_endpoint_buffer(CTRL_IN, dev_desc[IDX_MAX_PACKET_SIZE], p_send_data);
		send_len -= dev_desc[IDX_MAX_PACKET_SIZE];
		p_send_data += dev_desc[IDX_MAX_PACKET_SIZE];
	} else {
		if (send_len) {
			D12_write_endpoint_buffer(CTRL_IN, send_len, p_send_data);
			send_len = 0;
		} else {
			if (need_zero_packet) {
				D12_write_endpoint_buffer(CTRL_IN, send_len, p_send_data);
				need_zero_packet = 0;
			}
		}
	}
}	

static void parse_setup_packet(unsigned char *buf)
{
	unsigned char bmRequestType, bRequest;
	unsigned short wValue, wIndex, wLength;
	
	//printf("parse setup packet:\n");
	bmRequestType = buf[0];
	bRequest = buf[1];
	wValue = buf[2] + (buf[3] << 8);
	wIndex = buf[4] + (buf[5] << 8);
	wLength = buf[6] + (buf[7] << 8);
	
	if ((bmRequestType & DATA_PHASE_TRANSFER_DIRECTION) == DEV_TO_HOST) {
		//printf("device->host\nRequest type: ");
		switch (bmRequestType & TYPE) {
			case STANDARD:
				//printf("standard\n");
				switch (bRequest) {
					case GET_DESCRIPTOR:
						printf("GET_DESCRIPTOR: ");
						switch ((wValue >> 8) & 0xFF) {
							case DEVICE_DESCRIPTOR:
								printf("device\n");
								p_send_data = dev_desc;
								if (wLength > dev_desc[0]) {
									send_len = dev_desc[0];
									if (0 == (send_len % dev_desc[IDX_MAX_PACKET_SIZE])) {
										need_zero_packet = 1;
									}
								} else {
									send_len = wLength;
								}
								
								usb_endpoint0_send_data();
								break;
								
							case CONFIGURATION_DESCRIPTOR:
								printf("configuration\n");
								break;

							case INTERFACE_DESCRIPTOR:
								printf("interface\n");
								break;
							
							case ENDPOINT_DESCRIPTOR:
								printf("endpoint\n");
								break;
							
							case STRING_DESCRIPTOR:
								printf("string\n");
								break;	
							
							default:
								printf("unknown\n");
								break;
						}
						break;
					default:
						break;
				}
				break;
			case CLASS:
				printf("class\n");
				break;
			case VENDOR:
				printf("vendor\n");
				break;
			default:
				printf("Unknown request type %bx\n", bmRequestType);
				break;
		}
	} else { // HOST_TO_DEV
		printf("host->device ");
		switch (bmRequestType & TYPE) {
			case STANDARD:
				printf("standard output request: ");
				break;
			case CLASS:
				printf("class ");
				break;
			case VENDOR:
				printf("vendor ");
				break;
			default:
				printf("Unknown request type %bx\n", bmRequestType);
				break;
		}
	}
}

void usb_endpoint0_in(void)
{
	printf("endpoint 0 input\n");
	D12_read_endpoint_last_transaction_status(CTRL_IN);
	
	usb_endpoint0_send_data();
}

void usb_endpoint0_out(void)
{
	printf("endpoint 0 output\n");

	if (D12_read_endpoint_last_transaction_status(CTRL_OUT) & SETUP_PACKET) {
		D12_read_endpoint_buffer(CTRL_OUT, 16, Buffer);	
		D12_ack_setup();
		D12_clr_buffer();
		parse_setup_packet(Buffer);
	} else {
		D12_read_endpoint_buffer(CTRL_OUT, 16, Buffer);	
		D12_clr_buffer();
	}
}

void usb_endpoint1_in(void)
{
	printf("endpoint 1 input\n");
}

void usb_endpoint1_out(void)
{
	printf("endpoint 1 output\n");
}

void usb_endpoint2_in(void)
{
	printf("endpoint 2 input\n");
}

void usb_endpoint2_out(void)
{
	printf("endpoint 2 output\n");
}