#include "main.h"
#include <stdarg.h>

/**
 * print_c - prints char type to stdout
 * @args: va_list variable
 * Return: count
 */

int print_c(va_list args)
{
	int count = 0;
	char c = va_arg(args, int);

	_putchar(c);
	count++;

	return (count);
}
