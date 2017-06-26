#include <stdio.h>
#include <util/delay.h>

#include "uart.h"


int main(void) {    

    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
                
    char input;

    while(1) {
        printf("Oi ");
        puts("Mundo!");   
        _delay_ms(1000);	  
    }
        
    return 0;
}
