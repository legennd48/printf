/**
 * print_b - prints a binary equivalent of an unsigned decimal
 * @args: va_list argument parameters
 *
 * Return: number of characters printed
 */
#include "main.h"
#include <stdarg.h>
int print_b(va_list args)
{
	unsigned int num, rev_bin = 0;
	int count = 0;

	num = va_arg(args, unsigned int);
	/* Sorting out the 'zero' edge case */
	if (!num)
	{
		count += _putchar('0');
		return (count);
	}
	/*Converting the decimal to its reversed binary form */
	while (num)
	{
		rev_bin = (rev_bin * 10) + (num % 2);
		num /= num / 2;
	}
	/* Reversing the reversed binary to obtain binary */
	while (rev_bin)
	{
		count += _putchar('0' + (rev_bin % 10));
		rev_bin /= 10;
	}
	return (count);
}
