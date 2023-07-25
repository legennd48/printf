#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_R - Encrypts string with ROT13 cipher and prints it
 * @args: Argument list containing the string to be encrypted
 * Return: Number of characters printed
 */

int print_R(va_list args)
{
	int i, j, flag = 0, count = 0;
	char *str = va_arg(args, char *), *null = "(null)";
	char norm[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char r13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
	{
		write(1, null, 6);
		return (6);
	}
	if (str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		flag = 0;

		for (j = 0; norm[j] != '\0'; j++)
		{
			if (str[i] == norm[j])
			{
				_putchar(r13[j]);
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
