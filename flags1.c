#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * _itos - Convert an integer to a string
 * @num: The integer to be converted
 * Return: Pointer to the result string
 */
char *_itos(int num)
{
	int temp, len = 0, i, sign = 0;
	long int n = num;
	char *str;

	if (num == 0)/* Handle 0 explicitly, otherwise empty string is printed */
	{
		str = (char *)malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		sign = 1; /* Record the negative sign */
		n = -n; /* Convert the number to positive */
		len++; /* Increment length to account for the negative sign */
	}
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0'; /* Null-terminate the string */
	/* Fill the string from right to left with digits */
	for (i = len - 1; i >= sign; i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	/* Add the negative sign if necessary */
	if (sign)
		str[0] = '-';

	return (str);
}

/**
 * print_ld - Print a long int number
 * @args: Argument list containing the number to be printed
 * Return: Number of characters printed
 */
int print_ld(va_list args)
{
	long int num = va_arg(args, long int);
	char *buffer; /* Buffer to hold the number as a string*/
	int count = 0;

	buffer = _itos(num);
	while (buffer[count] != '\0')
	{
		_putchar(buffer[count]);
		count++;
	}

	return (count);
}
