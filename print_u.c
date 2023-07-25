#include "main.h"
#include <stdlib.h>

/**
 * print_u - prints unsigned int.
 * @args: va_list args received
 * Return: number of chars printed to stdout
 */

int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	unsigned int num = n, divisor = 1, digit;

	/* Handle the special case of num being 0 */
	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	/* Calculate the number of digits in the unsigned integer */
	while (num / 10 != 0)
	{
		divisor *= 10;
		num /= 10;
	}

	/* Print the digits of the unsigned integer */
	while (divisor > 0)
	{
		digit = n / divisor;
		count += _putchar(digit + '0');
		n = n - (digit * divisor);
		divisor /= 10;
	}

	return (count);
}
/**
 * print_o - prints int in octal
 * @args: va_list args received
 * Return: number of chars printed to stdout
 */

int print_o(va_list args)
{
	long int num = va_arg(args, long int), temp = num;
	int count = 0, *holder, i;

	if (num < 0)
		return (-1);

	/* special case: Handle the number 0 */
	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	/* Calculate the number of octal digits */
	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;

	/* Allocate memory for the holder to store octal digits */
	holder = malloc(count * sizeof(int));
	if (holder == NULL) /* Check if memory allocation is successful */
		return (-1);

	/* Store the octal digits in the holder */
	for (i = 0; i < count; i++)
	{
		holder[i] = temp % 8;
		temp /= 8;
	}

	/* Print the octal digits in reverse order */
	for (i = count - 1; i >= 0; i--)
	{
		count += _putchar(holder[i] + '0');
	}

	/* Free the dynamically allocated memory */
	free(holder);

	return (count);
}
