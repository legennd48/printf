#include "main.h"
#include <stdarg.h>

/**
 * _itos - Convert an integer to a string
 * @num: The integer to be converted
 * @str: The buffer to store the result string
 * Return: Pointer to the result string
 */
char *_itos(int num, char *str)
{
	int i = 0, j, rem;
	int isNeg = 0;
	char temp;

    /* Handle 0 explicitly, otherwise empty string is printed */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	/* Handle negative numbers */
	if (num < 0)
	{
		isNeg = 1;
		num = -num;
	}
	/* Convert the number to a string in reverse order */
	while (num != 0)
	{
		rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}
	/* Add the negative sign */
	if (isNeg)
		str[i++] = '-';
	/* Add '\0' and reverse the string */
	str[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - 1 - j];
		str[i - 1 - j] = temp;
	}
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
	char buffer[22]; /* Buffer to hold the number as a string*/
	int count = 0;

	_itos(num, buffer);
	while (buffer[count] != '\0')
	{
		_putchar(buffer[count]);
		count++;
	}

	return (count);
}
