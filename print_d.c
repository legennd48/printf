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
	int num = va_arg(args, int), count = 0;

	if (num < 0)
	{
		/* Handle negative numbers: print '-' and convert to absolute value */
		num = -num;
		count += _putchar('-');
	}
	/* Call print_num function to print the digits of the number */
	count += print_num(num);

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

/*
*	 Reverse the digits of the number
*	while (num != 0)
*	{
*		rev_num = rev_num * 10 + num % 10;
*		num /= 10;
*	}
*	 Print each digit by reversing the reversed number
*	while (rev_num != 0)
*	{
*		 Print the digit
*		count += _putchar('0' + rev_num % 10);
*		rev_num /= 10;
*	}
*/
	return (count);
}
