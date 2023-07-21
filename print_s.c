/**
 * print_s - print a string to standard output
 * @s: points to the string to be printed
 *
 * Return: number of characters printed on success
 */
#include "main.h"
int print_s(va_list args)
{
	int i = 0, count = 0;
	char *s;

	s = va_arg(args, char *s);

	if (s == NULL)
	{
		_putchar('\n');
		return (-1);
	}

	while(s[i])
	{
		_putchar(s[i]);
		count++
		i++;
	}
	_putchar('\n');
	return (count);
}
