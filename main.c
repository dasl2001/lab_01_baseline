#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "serial.h"
#include "led.h"



void main(void)
{
    char buffer[100];
    pinDirection(&DDRB, OUTPUT, PB1);
    setHigh(&PORTB, PB1);
    uart_init();
    //blinkLed(); 
    while(1)
    {
        print_char('A'); //skirver ut en char
        print_string("David Slivo\r"); //skirver ut en char array
        print(); //skiver ut char som är skickad med keyboard
    }
}
