#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * print_R - Encrypts string with ROT13 cipher and prints it
 * @args: Argument list containing the string to be encrypted
 * Return: Number of characters printed
 */
int print_R(va_list args)
{
	int count = 0, i;
	char *str, *r13, *null = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
		{
			_putchar(null[i]);
			count++;
		}
		return (count);
	}
	else if (str[0] == '\0')
		return (count);
	r13 = malloc(sizeof(char) * (_strlen(str) + 1));
	if (r13 == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			r13[i] = str[i] + 13;
			if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
				r13[i] -= 26;
		}
		else
			r13[i] = str[i];
	}
	r13[i] = '\0';
	count = 0;
	while (r13[count])
	{
		_putchar(r13[count]);
		count++;
	}
	free(r13);
	return (count);
}
