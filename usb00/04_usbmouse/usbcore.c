#include <stdio.h>
#include "usbcore.h"

unsigned char idata Buffer[16];
unsigned char conf_status;
unsigned char ep1_in_is_busy;

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

#define RECIPIENT (0x1F)
#define DEVICE (0x0)
#define INTERFACE (0x1)
#define EP (0x2)
#define OTHER (0x3)

#define IDX_MAX_PACKET_SIZE 7
unsigned char *p_send_data;
unsigned short send_len;
unsigned char need_zero_packet;
#define IDX_MANUFACTURE_STRING_DESCRIPTOR 0x01
#define IDX_PRODUCT_STRING_DESCRIPTOR 0x02
#define IDX_SERIAL_NUMBER_STRING_DESCRIPTOR 0x03
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
	IDX_MANUFACTURE_STRING_DESCRIPTOR, /* iManufacturer: Index of Manufacturer String Descriptor */
	IDX_PRODUCT_STRING_DESCRIPTOR, /* iProduct: Index of Product String Descriptor */
	IDX_SERIAL_NUMBER_STRING_DESCRIPTOR, /* iSerialNumber: Index of Serial Number String Descriptor */
	0x01 /* bNumConfigurations: Number of Possible Configurations */
};

unsigned char code report_desc[] =
{
	/* Prefix: D[7:4] bTag, D[3:2], bType; D[1:0], bSize */
	0x05, 0x01,
	0x09, 0x02,
	0xa1, 0x01,
	0x09, 0x01,
	0xa1, 0x00,
	0x05, 0x09,
	0x19, 0x01,
	0x29, 0x03,
	0x15, 0x00,
	0x25, 0x01,
	0x95, 0x03,
	0x75, 0x01,
	0x81, 0x02,
	0x95, 0x01,
	0x75, 0x05,
	0x81, 0x03,
	0x05, 0x01,
	0x09, 0x30,
	0x09, 0x31,
	0x09, 0x38,
	0x15, 0x81,
	0x25, 0x7f,
	0x75, 0x08,
	0x95, 0x03,
	0x81, 0x06,
	0xc0,
	0xc0
};

unsigned char code conf_desc[9+9+9+7] = {
	/* --- configuration descriptor #1 --- */
	0x09, /*bLength: size of descriptor in bytes */
	0x02, /* bDescriptorType: a constant */
	sizeof(conf_desc) & 0xFF, //wTotalLength
	(sizeof(conf_desc) >> 8) & 0xFF,
	0x01, /* bNumInterfaces */
	0x01, /* bConfiguration */
	0x00, /* iConfiguration */
	0x80, /* bmAttributes */
	0x32, /* bMaxPower : 0x32 * 2mA = 100mA */
	
	/* --- interface descriptor #0 --- */
	0x09, /* bLength */
	0x04, /* bDescriptorType */
	0x00, /* bInterfaceNumber */
	0x00, /* bAlternateSetting */
	0x01, /* bNumEndpoints */
	0x03, /* bInterfaceClass: mouse HID = 3 */
	0x01, /* bInterfaceSubClass */
	0x02, /* bInterfaceProtocol */
	0x00, /* iConfiguration */
 
	/* --- device class definition for HID --- */
	0x09, /* bLength */
	0x21, /* bDescriptorType */
	0x10, /* bcdHID: HID version 1.1 */
	0x01,
	0x21, /* bCountyCode */
	0x01, /* bNumDescriptors */
	0x22, /* bDescritporType */
	sizeof(report_desc) & 0xFF, /* bDescriptorLength */
	(sizeof(report_desc) >> 8) & 0xFF,
 
	/* --- endpoint descriptor --- */
	0x07, /* bLength */
	0x05, /* bDescriptorType */
	0x81, /* bEndpointAddress */
	0x03, /* bmAttributes */
	0x10, /* wMaxPacketSize */
	0x00,
	0x0A /* bInterval */
};

unsigned char code language_id[] = 
{
	0x04, /* bLength */
	0x03, /* bDescriptorType */
	0x09, /* English (United States) */
	0x04
};

unsigned char code manufacture_descriptor[] = 
{
	20,
	0x03,
	'A', 0x0,
	'v', 0x0,
	'e', 0x0,
	'r', 0x0,
	'M', 0x0,
	'e', 0x0,
	'd', 0x0,
	'i', 0x0,
	'a', 0x0
};

unsigned char code product_string_descriptor[] = 
{
	18,
	0x03,
	'U', 0x0,
	's', 0x0,
	'b', 0x0,
	'M', 0x0,
	'o', 0x0,
	'u', 0x0,
	's', 0x0,
	'e', 0x0
};

unsigned char code serial_number_string_descriptor[] = 
{
	22,
	0x03,
	'2', 0x0,
	'0', 0x0,
	'1', 0x0,
	'6', 0x0,
	'/', 0x0,
	'0', 0x0,
	'4', 0x0,
	'/', 0x0,
	'2', 0x0,
	'1', 0x0
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
		printf("device->host\nRequest type: ");
		switch (bmRequestType & TYPE) {
			case STANDARD:
				printf("standard\n");
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
								p_send_data = conf_desc;
								send_len = conf_desc[3];
								send_len = (send_len << 8) + conf_desc[2];
								if (wLength > send_len) {
									send_len = dev_desc[0];
									if (0 == (send_len % dev_desc[IDX_MAX_PACKET_SIZE])) {
										need_zero_packet = 1;
									}
								} else {
									send_len = wLength;
								}
								usb_endpoint0_send_data();
								break;

							case INTERFACE_DESCRIPTOR:
								printf("interface\n");
								break;
							
							case ENDPOINT_DESCRIPTOR:
								printf("endpoint\n");
								break;
							
							case STRING_DESCRIPTOR:
								printf("string: ");
								switch (wValue & 0xFF) {
									case 0:
										printf("language id\n");
										p_send_data = language_id;
										send_len = language_id[0];
										break;
									
									case IDX_MANUFACTURE_STRING_DESCRIPTOR:
										printf("manufacture\n");
										p_send_data = manufacture_descriptor;
										send_len = manufacture_descriptor[0];
										break;
									
									case IDX_PRODUCT_STRING_DESCRIPTOR:
										printf("product\n");
										p_send_data = product_string_descriptor;
										send_len = product_string_descriptor[0];
										break;
									
									case IDX_SERIAL_NUMBER_STRING_DESCRIPTOR:
										printf("serial number\n");
										p_send_data = serial_number_string_descriptor;
										send_len = serial_number_string_descriptor[0];
										break;

									default:
										printf("Unhandled string %d\n", wValue);
										send_len = 0;
										need_zero_packet = 1;
										break;
								}
								if (wLength > send_len) {
									if (0 == (send_len % dev_desc[IDX_MAX_PACKET_SIZE])) {
										need_zero_packet = 1;
									}
								} else {
									send_len = wLength;
								}
								usb_endpoint0_send_data();
								break;	
							
							case REPORT_DESCRIPTOR:
								printf("report\n");
								p_send_data = report_desc;
								send_len = sizeof(report_desc);
															if (wLength > send_len) {
								if (0 == (send_len % dev_desc[IDX_MAX_PACKET_SIZE])) {
										need_zero_packet = 1;
									}
								} else {
									send_len = wLength;
								}
								usb_endpoint0_send_data();
								break;
							
							default:
								printf("Unhandled 0x%X\n", wValue);
								break;
						}
						break;
						
					default:
						printf("Unknown request %bx\n", bRequest);
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
		printf("host->device\nRequest type: ");
		switch (bmRequestType & TYPE) {
			case STANDARD:
				printf("standard\n");
				switch (bRequest) {
					case GET_STATUS:
						printf("GET_STATUS\n");
						break;
					case CLEAR_FEATURE:
						break;
					case SET_FEATURE:
						printf("CLEAR_FEATURE\n");
						break;
					case SET_ADDRESS:
						printf("SET_ADDRESS 0x%X\n", wValue);
						D12_set_usb_addr(wValue & 0xff);
						send_len = 0;
						need_zero_packet = 1;
						usb_endpoint0_send_data();
						break;
					case GET_DESCRIPTOR:
						printf("GET_DESCRIPTOR\n");
						break;
					case SET_DESCRIPTOR:
						printf("SET_DESCRIPTOR 0x%X\n", wValue);

						break;
					case GET_CONFIGURATION:
						printf("GET_CONFIGURATION\n");
						break;
					case SET_CONFIGURATION:
						printf("SET_CONFIGURATION\n");
						conf_status = wValue & 0xFF;
						D12_set_endpoint(conf_status);
						send_len = 0;
						need_zero_packet = 1;
						usb_endpoint0_send_data();
						break;
					default:
						printf("Unhandled request %bx\n", bRequest);
						break;
				}
				break;
			case CLASS:
				printf("class: ");
				switch (bRequest) {
					case SET_IDLE:
						printf("SET_IDLE\n");
						send_len = 0;
						need_zero_packet = 1;
						usb_endpoint0_send_data();
						break;
					default:
						printf("Unhandled request %bx\n", bRequest);
						break;
				}
				break;
			case VENDOR:
				printf("vendor\n");
				break;
			default:
				printf("Unknown request type %bx\n", bmRequestType);
				break;
		}
	}
}

void usb_endpoint0_in(void)
{
	printf("ep0 input\n");
	D12_read_endpoint_last_transaction_status(CTRL_IN);
	
	usb_endpoint0_send_data();
}

void usb_endpoint0_out(void)
{
	printf("ep0 output\n");

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
	printf("ep1 input\n");
	D12_read_endpoint_last_transaction_status(ENDP_1_IN);
	ep1_in_is_busy = 0;
}

void usb_endpoint1_out(void)
{
	printf("ep1 output\n");
}

void usb_endpoint2_in(void)
{
	printf("ep2 input\n");
}

void usb_endpoint2_out(void)
{
	printf("ep2 output\n");
}