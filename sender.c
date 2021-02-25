

#include <mega16.h>
#include <delay.h>

// Declare your global variables here
char ch;
int left , right;
void main(void)
{
// Declare your local variables here
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Fast PWM top=0xFF
// OC0 output: Non-Inverted PWM
// Timer Period: 2.048 ms
// Output Pulse(s):
// OC0 Period: 2.048 ms Width: 0 us
TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

DDRB.3=1;
DDRD=0x00;
PORTD=0xff;
while (1)
      {     
        ch=PIND;
        left = ch & 0b00001111;
        right = (ch & 0b11110000)>>4;
        left =(left+1)*15;
        right = (right+1)*15;
        TCNT0=0;
        OCR0=left;
        delay_us(2048);
        TCNT0=0;
        OCR0=right;       
        delay_us(2048);
      }
}
