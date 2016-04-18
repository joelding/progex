#include <stdio.h>
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

void D12_write_byte(unsigned char val)
{
	D12_set_addr(D12_ADDR_DATA);
	D12_clr_wr();
	D12_set_port_out();
	D12_set_data(val);
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

void D12_select_endpoint(unsigned char endp)
{
	D12_write_cmd(endp);
}

/*
endp: 
*/
unsigned char D12_read_endpoint_buffer(unsigned char endp, unsigned char buf_len, unsigned char *buf)
{
	unsigned char len, i;
	
	D12_select_endpoint(ID_SELECT_ENDPOINT + endp);
	D12_write_cmd(ID_READ_BUFFER);
	D12_read_byte(); /* first byte is reserved */
	len = D12_read_byte();
	
	printf("Read endpoint %bu, ", endp);
	
	if (len > buf_len) {
		len = buf_len;
	}
	
	printf("buffer %bu bytes\n", len);
	
	for (i = 0; i < len; ++i) {
		D12_clr_rd();
		*(buf + i) = D12_get_data();
		D12_set_rd();
		
		printf("%02bx ", *(buf + i));
		
		if (((i + 1) % 16) == 0) {
			printf("\n");
		}
	}
	
	if ((len % 16) != 0) {
		printf("\n");
	}
	
	return len;
}

void D12_validate_buffer(void)
{
	D12_write_cmd(ID_VALIDATE_BUFFER);
}

unsigned char D12_write_endpoint_buffer(unsigned char endp, unsigned char buf_len, unsigned char *buf)
{
	unsigned char i;
	
	D12_select_endpoint(ID_SELECT_ENDPOINT + endp);
	D12_write_cmd(ID_WRITE_BUFFER);
	D12_write_byte(0);
	D12_write_byte(buf_len);
	
	printf("Write endpoint %bu, ", endp);
	printf("buffer %bu bytes\n", buf_len);
	
	D12_set_port_out();
	
	for (i = 0; i < buf_len; ++i) {
		D12_clr_wr();
		D12_set_data(*(buf + i));
		D12_set_wr();
		
		printf("%02bx ", *(buf + i));
		
		if (((i + 1) % 16) == 0) {
			printf("\n");
		}
	}
	
	D12_set_port_in();
	D12_validate_buffer();
	
	return buf_len;
}

void D12_clr_buffer(void)
{
	D12_write_cmd(ID_CLR_BUFFER);
}

void D12_ack_setup(void)
{
	D12_select_endpoint(CTRL_IN);
	D12_write_cmd(ID_ACK_SETUP);
	D12_select_endpoint(CTRL_OUT);
	D12_write_cmd(ID_ACK_SETUP);
}

unsigned char D12_read_endpoint_last_transaction_status(unsigned char endp)
{
	D12_write_cmd(ID_READ_LAST_TRANSACTION_STATUS + endp);
	
	return D12_read_byte();
}

