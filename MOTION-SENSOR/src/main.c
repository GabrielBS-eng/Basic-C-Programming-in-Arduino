#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
        DDRB |= (1 << DDB4); // habilita o pino 12 para saída digital (OUTPUT).
	while(1)
        {
		if(PIND & (1 << PIND2))
		{
	                PORTB |= (1 <<PORTB4); // liga o LED.
        	        _delay_ms(50); // espera 1 segundo (1000 milissegundos).
		}
		else
		{
			PORTB &= ~(1 <<PORTB4);
			_delay_ms(50);
		}
        }
}
