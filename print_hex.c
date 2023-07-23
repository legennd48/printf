/**
 * print_X - formats an unsigned int to an hex in caps
 * @args: argument parameters
 *
 * Return: character count
 */
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
int print_X(va_list args)
{
	int i;
	int *array;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	/* Find number of integers gotten during conversion */
	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	/* Use number of integers to allocate storage for conversion */
	array = malloc(count * sizeof(int));

	/* Conversion from decimal to hexadecimal */
	for (i = 0; i < count; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	/* Conversion from hex_decimal to hex_codes */
	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}

/**
 * print_x - formats an unsigned int to an hex in small case
 * @args: argument parameters
 *
 * Return: character count
 */
int print_x(va_list args)
{
	int i;
	int *array;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}
