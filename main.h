#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} spc_dt;

char _write(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_format(const char *format, va_list args);
int print_spec(char format, va_list args);
int print_invalid_spec(char prev_format, char format, int count);
int print_integer(va_list args);
void recursion_integer(int a);
int print_int_binary(va_list args);
void recursion_int_binary(int a);
int validate_char(char type);

#endif /* MAIN_H */
