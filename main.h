#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
unsigned int print_integer(int num);
unsigned int print_string(char *s);
unsigned int print_base(unsigned int n, int base);
int _printf(const char *format, ...);
unsigned int print_unsigned(unsigned int n);
unsigned int print_hexadecimal(unsigned int n,int a);

#endif

