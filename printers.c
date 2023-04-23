#include "main.h"
#include <stdarg.h>

/**
  * print_char - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int print_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}

		return (i);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
  * print_integer - Prints a integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_integer(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;

	if (m < 0)
	{
		_write('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	recursion_integer(m);
	return (count);
}

/**
  * recursion_integer - Prints a integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void recursion_integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		recursion_integer(t / 10);
	_write(t % 10 + '0');
}
