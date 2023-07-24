#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * print_r - prints a string in reverse
 * @args: va_list argument
 * Return: number or chars printed
 */

int print_r(va_list args)
{
	int count = 0, lent;
	char *s = make_buffer(), *tmp, *n = "(null)";

	if (s == NULL)
		return (-1);

	tmp = va_arg(args, char *);
	if (tmp == NULL || tmp[0] == '\0')
	{
		write(1, n, _strlen(n));
		_putchar('\n');
		free(s);
		return (6);
	}
	lent = _strlen(tmp);
	while (lent > 0)
	{
		s[count] = tmp[lent - 1];
		count++;
		lent--;
	}

	s[count] = '\0';
	putstring(s, count);
	free(s);
	return (count);
}
