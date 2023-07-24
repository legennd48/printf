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
	int i, j, flag = 0, count = 0;
	char *str = va_arg(args, char *), *null = "(null)";
	char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char r13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
		{
			_putchar(null[i]);
			count++;
		}
		return (count);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (str[i] == alpha[j])
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
