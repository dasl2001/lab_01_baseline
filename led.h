#ifndef LED_H_
#define LED_H_

typedef enum{
    INPUT,
    OUTPUT
} Direction;

void blinkLed();
void delay(unsigned long milliseconds);
void toggleBit(uint8_t* Register, uint8_t bit);
void setHigh(uint8_t* Register, uint8_t bit);
void setBLow(uint8_t* Register, uint8_t bit);
void pinDirection(uint8_t* Register, Direction direction, uint8_t bit);

#endif