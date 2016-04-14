#include "pdiusbd12.h"

void D12_write_cmd(unsigned char cmd)
{
	D12_set_addr(D12_ADDR_CMD);
	D12_clr_wr();
	D12_set_port_out();
	D12_set_data(cmd);
	D12_set_wr();
	D12_set_port_in();
}

unsigned char D12_read_byte(void)
{
	unsigned char tmp;
	
	D12_set_addr(D12_ADDR_DATA);
	D12_clr_rd();
	tmp = D12_get_data();
	D12_set_rd();
	
	return tmp;
}

unsigned short D12_read_id(void)
{
	unsigned short id;
	
	D12_write_cmd(ID_READ);
	id = D12_read_byte();
	id |= ((unsigned short) D12_read_byte()) << 8;
	
	return id;
}