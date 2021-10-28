#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "serial.h"
#include "led.h"



void main(void)
{
    char buffer[100];
    pin_direction(&DDRB, OUTPUT, PB1);
    set_high(&PORTB, PB1);
    uart_init();
    //blink_led(); 
    while(1)
    {
        //blink_led(); 
        //print_char('A'); //skirver ut en char
        //print_string("David Slivo\r"); //skirver ut en char array
        //print(); //skiver ut char som är skickad med keyboard
        store_command(buffer);
        execute_command(buffer);
    }
}
