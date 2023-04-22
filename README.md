## Peer Project - Printf

A project similar to the C programming language printf() function from the <stdio.h> header that displays texts based on specified formats (%d, %i, %f, %c, %s, %x)

* `_printf()` - The formatted output conversion
* Returns the number of characters printed(excluding the null byte used to end output to strings)
* Writes output to stdout, the standard output stream
* `format` is a character string. The format string is composed of zero or more directives. See `man 3 printf` for more detail.
* Conversion specifiers:
	* c
	* s
	* %
	* d & i

### Use Case

#include "main.h"

`int _printf(const char *format, ...);`
