#ifndef __PDIUSBD12_H__
#define __PDIUSBD12_H__

#include <STC89C5xRC.H>

#define D12_DATA P0
#define D12_A0 P35
#define D12_WR P36
#define D12_RD P37
#define D12_INT P32

#define D12_ADDR_CMD 1
#define D12_ADDR_DATA 0

#define D12_set_addr(addr) D12_A0 = (addr)

#define D12_set_wr() D12_WR = 1
#define D12_clr_wr() D12_WR = 0

#define D12_set_rd() D12_RD = 1
#define D12_clr_rd() D12_RD = 0

#define D12_get_int() D12_INT

#define D12_get_data() D12_DATA
#define D12_set_data(val) D12_DATA = (val);

#define D12_set_port_in() D12_DATA = 0xFF

#define D12_set_port_out()

#define ID_SET_ADDR_ENABLE 0xD0
#define ID_SET_EP_ENABLE 0xD8

/* initialization commands: */
#define ID_SET_MODE 0xF3

/* data flow commands: */
#define ID_READ_INTERRUPT_REGISTER 0xF4

#define CTRL_OUT 0x00
#define CTRL_IN 0x01
#define ENDP_1_OUT 0x02
#define ENDP_1_IN 0x03
#define ENDP_2_OUT 0x04
#define ENDP_2_IN 0x05
#define EP_NUM(x) ((x) / 2)
#define EP_DIR(x) (((x) & 0x1) ? "IN" : "OUT")

/*	select endpoint */
#define ID_SELECT_ENDPOINT 0x00

/*	read last transaction status */
#define ID_READ_LAST_TRANSACTION_STATUS 0x40
#define DATA_TRANSCEIVE_SUCCESS (1 << 0)
#define ERROR_CODE (0x7 << 1)
#define SETUP_PACKET (1 << 5)
#define DATA_01_PACKET (1 << 6)
#define NOT_READ (1 << 7)

#define ID_READ_BUFFER 0xF0
#define ID_WRITE_BUFFER 0xF0

#define ID_ACK_SETUP 0xF1
#define ID_CLR_BUFFER 0xF2
#define ID_VALIDATE_BUFFER 0xFA
#define ID_READ 0xFD

#define ID_SET_ENDPOINT_ENABLE 0xD8
#define ENDPT_ENABLE 0x1
#define ENDPT_DISABLE 0x0

void D12_write_cmd(unsigned char);
void D12_write_byte(unsigned char);
unsigned char D12_read_byte(void);
unsigned short D12_read_id(void);
void D12_select_endpoint(unsigned char);
unsigned char D12_read_endpoint_buffer(unsigned char, unsigned char, unsigned char *);
unsigned char D12_write_endpoint_buffer(unsigned char, unsigned char, unsigned char *);
void D12_clr_buffer(void);
void D12_ack_setup(void);
unsigned char D12_read_endpoint_last_transaction_status(unsigned char);
void D12_set_usb_addr(unsigned char);
void D12_set_endpoint(unsigned char);




#endif /* __PDIUSBD12_H__ */