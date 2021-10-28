#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "serial.h"

void uart_init()
{
unsigned long BAUD = 38400UL;
unsigned long UBRR = ((F_CPU/(16*BAUD))-1);

//Sätter baud rate                    
UBRR0H = (UBRR & 0xFF00)>>8; //bitshift 8 gånger.
UBRR0L = UBRR & 0x00FF; //

//Gör det möjligt med receiver och transmitter
setHigh(&UCSR0B,RXEN0);
setHigh(&UCSR0B,TXEN0);

//Ställer in typ av paritetsgenerering och kontroll. Ställ in på ingen paritet.
setLow(&UCSR0C,UPM01);
setLow(&UCSR0C,UPM00);

//Ställer in antalet stoppbitar som ska infogas av sändaren. Ställ in på 1 stoppbit.
setLow(&UCSR0C,USBS0);

//Ställer in antalet databitar i en ram som mottagaren och sändaren använder. Ställ in på 8bit
setLow(&UCSR0C,UCSZ02); 
setHigh(&UCSR0C,UCSZ01);
setHigh(&UCSR0B,UCSZ00);
}


void print_char(unsigned char data)//Skriver ut en char.
{
    while (!(UCSR0A & (1<<UDRE0))); //Kontrollerar att bufferten är tom och skrivbar, annars väntar den tills den är det.
    UDR0 = data; //Laddar UDR0 med data.
}

void uart_putchar(unsigned char data) //Skriver ut ett tecken. Om char är '\r' skriv först ut '\n' och skriv sedan ut char (som är '\r').
{ 
    if(data=='\r')
    {
        print_char('\n');
    }
    print_char(data);
}

void print_string(char* str) //Skriver ut en char array.
{ 
    int i = 0;
    while(str[i]!='\0')
    {
        print_char(str[i]);
        i++;
    }
}

unsigned char read_char() //Läser en char.
{   
    while (!(UCSR0A & (1<<RXC0))); //Kontrollerar om det finns oläst data i mottagningsbufferten.
    return UDR0; //returnerar char
}

void print() //Skriver ut det lästa char.
{
    print_char(read_char());
}