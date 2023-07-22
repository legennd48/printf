#include "main.h"
#include <stdarg.h>

/**
 * _printf - should behave like printf to print args
 * based on specified format
 * @format: the specified format to print
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	specifier id[] = {
		{'c', print_c}, {'o', print_o},
		{'s', print_s}, {'u', print_u}, /* added u and o */
		{'d', print_d},
		{'i', print_i}, /* added i and d */
		{'b', print_b}, /* added b */
		{0, NULL}
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			j = 0;

			while (id[j].type != 0)
			{
				if (id[j].type == format[i])
				{
					count += id[j].func(args); /* corrected count */
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	_putchar('\n');
	return (count);
}
