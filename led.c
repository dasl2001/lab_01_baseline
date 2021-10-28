#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void blink_led() //Blå LED Blinkar 
{
    while(1)
    {
        toggle_bit(&PORTB, PB1); 
        delay(500);
    }
}


void delay(unsigned long milliseconds) 
{
    while(milliseconds--)
    {
        _delay_ms(1);
    }
}


void toggle_bit(uint8_t* Register, uint8_t bit) 
{
    *Register^=(1<<bit);
}

void set_high(uint8_t* Register, uint8_t bit) 
{
    *Register|=(1<<bit);
}

void set_low(uint8_t* Register, uint8_t bit)
{
    *Register&=~(1<<bit);
}

void pin_direction(uint8_t* Register, Direction direction, uint8_t bit) //Ställer in nålriktning. Använder Enums.
{
    if(direction==INPUT)
    {
        set_low(Register, bit);
    }
    if(direction==OUTPUT)
    {
        set_high(Register, bit);
    }
}


