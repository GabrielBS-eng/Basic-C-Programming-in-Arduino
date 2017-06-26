
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "uart.h"
#include "ad.h"


int ad = 0;
int temp = 0;
char snum[10];


void pwm_init(void) {

	DDRB |= (1 << DDB1) | (1 << DDB2);  // PB1 is now output - OC1A e PB2 is now output - OC2A

	TCCR1A |= (1 << COM1A1); // overrides the normal port functionality of the I/O pin to OC1A - Output Compare Pin 
                                 // Pino PB1 do uC e Pino 9 do Kit Arduíno (Pag. 131).
	TCCR1A |= (1 << COM1B1); // overrides the normal port functionality of the I/O pin to OC1B (PB2) - Output Compare Pin (Pag. 131).
                                 // Pino PB2 do uC e Pino 10 do Kit Arduíno (Pag. 131).

	TCCR1A |= (1 << WGM11) | (1 << WGM10); // Timer/Counter Mode of Operation = Fast PWM-10-bit, TOP = 0x03FF, 
                                               // Update of OCR1x at = BOTTOM, TOV1 Flag Set on = TOP (Pag. 132)


	TCCR1B |= (1 << WGM12); // Timer/Counter Mode of Operation = Fast PWM-10-bit, TOP = 0x03FF, 
                                // Update of OCR1x at = BOTTOM, TOV1 Flag Set on = TOP (Pag. 132)


	TCCR1B |= (1 << CS11); // set prescaler to 8 and starts PWM (Tab 16-5, Pag. 134)
}


int main(void) {    

    int i = 0; // Loop variable
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    ad_init();
    pwm_init();


    while(1) {
	ad = ADCL;  // ADCL must be read first, then ADCH
	ad = (ADCH << 8) + ad;
	OCR1A = ad; // set pin PB1 PWM duty cycle
	OCR1B = ad; // set pin PB2 PWM duty cycle 
        printf("O valor do A/D %c: %d\r\n", 233, ad); 
	_delay_ms(100);
    }
        
    return 0;
}
