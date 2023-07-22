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
	unsigned int num, bit_mask;
	int i, count = 0, num_of_bits;

	num = va_arg(args, unsigned int);
	/* Sorting out the 'zero' edge case */
	if (!num)
	{
		count += _putchar('0');
		return (count);
	}
	/* Getting the number of bits of an unsigned int */
	num_of_bits = sizeof(unsigned int) * 8;
	/* Creating a bit mask */
	bit_mask = 1 << (num_of_bits - 1);
	/* Printing each bit from left to right */
	for (i = 0; i < num_of_bits; i++)
	{
		/*Bitwise AND operation to check current bit*/
		if (num & bit_mask)
			count += _putchar('1');
		else
			count += _putchar('0');
		/* Shift bit_mask to the right*/
		bit_mask = bit_mask >> 1;
	}
	return (count);
}
