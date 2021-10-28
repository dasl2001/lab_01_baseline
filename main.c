#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "serial.h"
#include "led.h"



void main(void)
{
    pinDirection(&DDRB, OUTPUT, PB1);
    setHigh(&PORTB, PB1);
    while(1)
    {
           blinkLed(); 
    }
}
