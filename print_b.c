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
	unsigned int num;
	int i, count = 0;
	char *binary_str;

	num = va_arg(args, unsigned int);
	binary_str = int_to_binary(num);
	for (i = 0; binary_str[i]; i++)
		count += _putchar(binary_str[i]);
	return (count);
}

/**
 * int_to_binary - converts int to binary
 * @num: an unsigned int
 *
 * Return: binary string on Success
 */
char *int_to_binary(unsigned int num)
{
	static char binary[33];
	int i, j = 0;

	for (i = 31; i >= 0; i--)
	{
		if (num & (1u << i))
			binary[j++] = '1';
		else if (j > 0)
			binary[j++] = '0';
	}
	if (j == 0)
		binary[j++] = '0';
	binary[j] = '\0';
	return (binary);
}

