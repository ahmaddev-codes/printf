#include <unistd.h>
#include "main.h"

/**
 * _write - A function that prints a character
 *
 * @c: The character to print
 *
 * Return: The charcater passed into the function
 */
char _write(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
