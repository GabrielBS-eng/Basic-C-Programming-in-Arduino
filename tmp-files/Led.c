#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   DDRB |= (1 << DDB5); // habilita o pino 13 para saída digital (OUTPUT).

   while(1)
   {
     PORTB |= (1 <<PORTB5);   // liga o LED.

      _delay_ms(25); // espera 1 segundo (1000 milissegundos).

      PORTB &= ~(1 <<PORTB5);  // desliga o LED.

      _delay_ms(25);         // espera 1 segundo.
   }
}
