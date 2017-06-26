#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB |= (1 << DDB4); // habilita o pino 13 para saída digital (OUTPUT).
	while(1)
	{
		PORTB |= (1 <<PORTB4); // liga o LED.
		_delay_ms(50); // espera 1 segundo (1000 milissegundos).
		PORTB &= ~(1 <<PORTB4); // desliga o LED.
		_delay_ms(50); // espera 1 segundo.
	}
}
