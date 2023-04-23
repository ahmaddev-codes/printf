#include "main.h"
#include <stdarg.h>

/**
 * _printf - A function that produces output
 * according to a format
 *
 * @format: The format of output to produce
 * @...: The rest of the arguments passed
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int length = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	length = print_format(format, args);
	
	va_end(args);

	return (length);
}
