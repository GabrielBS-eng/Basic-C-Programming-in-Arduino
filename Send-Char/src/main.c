#include <stdio.h>
#include "uart.h"
int main(void)
{
	uart_init();
	stdout = &uart_output;
	stdin = &uart_input;
	char input;
	while(1)
	{
		//puts("Hello world!\n");
		printf("Send a character:\n");
		input = getchar();
		printf("The sent character was: %c\n", input);
	}
	return 0;
}
