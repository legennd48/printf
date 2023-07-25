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

/**
 * print_k - Prints unknown specifier along with '%'
 * @args: Argument list containing the specifier to be printed
 * Return: Number of characters printed
 */
int print_k(va_list args)
{
	char c = va_arg(args, int);

	_putchar('%');
	_putchar(c);
	return (2);
}
