#include "main.h"
#include <stdarg.h>

/**
  * print_format - Prints a format
  *
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int print_format(const char *format, va_list args)
{
	int i = 0, count = 0;
	
	while (format && format[i + 1])
	{
		if (format[i] == '%')
		{
			if (format[i = 1] == '\0')
				return (-1);

			i++;
			
			while (format[i] == ' ')
				format++;
			
			if (format[i] == '%')
				count += _write(format[i]);
			
			if (validate_char(format[i] == 0))
				count += print_invalid_spec(format[i - 1], format[i], count);
			
			else
				count = print_spec(format[i], args);
		}

		else
			count += _write(format[i]);
		
		i++;
	}
	
	return (count);
}

/**
  * print_spec - Prints a valid specifier
  *
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier
  */
int print_spec(char format, va_list args)
{
	int i  = 0, length = 0;
	spc_dt types[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_int_binary},
		{NULL, NULL}
	};

	while (types[i].specifier)
	{
		if (*types[i].specifier == format)
			length = types[i].f(args);

		i++;
	}

	return (length);
}

/**
  * print_invalid_spec - Prints a invalid specifier
  *
  * @prev_format: The previous specifier of actual specifier
  * @format: The specifier to prints
  * @count: The current count before prints invalid specifiers
  *
  * Return: The current count after prints invalid specifiers
  */
int print_invalid_spec(char prev_format, char format, int count)
{
	count += _write('%');

	if (prev_format == ' ')
	{
		count += _write(' ');
		count += _write(format);
	}

	else
		count += _write(format);

	return (count);
}

/**
  * validate_char - validate the type
  *
  * @type: character to be comparate
  *
  * Return: 1 if char is equal to a type
  */
int validate_char(char type)
{
	char types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (types[i])
	{
		if (types[i] == type)
			return (1);
		i++;
	}

	return (0);
}
