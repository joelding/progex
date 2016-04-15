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

/* command ID */
#define ID_SET_MODE 0xF3
#define ID_READ_INT_REG 0xF4
#define ID_READ 0xFD

void D12_write_cmd(unsigned char);
void D12_write_byte(unsigned char);
unsigned char D12_read_byte(void);
unsigned short D12_read_id(void);


#endif /* __PDIUSBD12_H__ */