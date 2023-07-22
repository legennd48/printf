/**
 * print_s - print a string to standard output
 * @args: argunment parameters
 *
 * Return: number of characters printed on success
 */
#include "main.h"
#include <stddef.h>
#include <stdarg.h>
int print_s(va_list args)
{
	int i = 0, count = 0;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	if (s[0] == '\0')
	{
		_putchar('\n');
		return (-1);
	}

	while (s[i])
	{
		_putchar(s[i]);
		count++;
		i++;
	}

	/*_putchar('\n');*/
	return (count);
}
