#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void blinkLed() //Blå LED Blinkar 
{
    while(1)
    {
        toggleBit(&PORTB, PB1); 
        delay(500);
    }
}


void delay(unsigned long milliseconds) 
{
    while(milliseconds--){
        _delay_ms(1);
        }
}


void toggleBit(uint8_t* Register, uint8_t bit) 
{
    *Register^=(1<<bit);
}

void setHigh(uint8_t* Register, uint8_t bit) 
{
    *Register|=(1<<bit);
}

void setLow(uint8_t* Register, uint8_t bit)
{
    *Register&=~(1<<bit);
}

void pinDirection(uint8_t* Register, Direction direction, uint8_t bit) //Ställer in nålriktning. Använder Enums.
{
    if(direction==INPUT){
        setLow(Register, bit);
    }
    if(direction==OUTPUT){
        setHigh(Register, bit);
    }
}


