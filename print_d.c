#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_d - print a signed base 10 number
 * @args: va_list arguments
 * Return: number of characters printed on success
 */

int print_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12]; /* Buffer to hold the number */
	int count = 0;

	_itos(num, buffer);
	while (buffer[count] != '\0')
	{
		_putchar(buffer[count]);
		count++;
	}

	return (count);
}
/**
 * print_i - prints signed integer
 * @args: va_list argument
 * Return: number of characters printed on success
 */

int print_i(va_list args)
{
	/* Use print_d to handle %i format specifier (same as %d for printf) */
	return (print_d(args));
}

/**
 * print_num - prints numbers recieved as argument by reversing
 * and printing one digit at a time.
 * @num: number to be printed
 * Return: number of characters printed on success
 */

int print_num(int num)
{
	int count = 0; /* rev_num = 0, */

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		/* Special case: number is 0, print '0' directly */
		count += _putchar('0');
		return (count);
	}

	/* Recursively print digits from left to right */
	if (num / 10 != 0)
		count += print_num(num / 10);

	count += _putchar('0' + num % 10);

	return (count);
}
