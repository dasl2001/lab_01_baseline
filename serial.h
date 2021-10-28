#ifndef SERIAL_H_
#define SERIAL_H_

void uart_init();
void uart_putchar(unsigned char data);
void print_char(unsigned char data);
void print_string(char* str);
unsigned char read_char();
void print();
#endif