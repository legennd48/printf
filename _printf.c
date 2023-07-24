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
		{'c', print_c}, {'o', print_o}, {'s', print_s}, {'u', print_u},
		{'d', print_d}, {'i', print_i}, {'x', print_x}, {'X', print_X},
		{'S', print_S}, {'b', print_b}, {'R', print_R}, {'r', print_r}, {0, NULL} };
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0')
	    || (format[0] == '%' && format[1] == ' '))
		return (-1);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			j = 0;
			while (id[j].type != 0)
			{
				if (id[j].type == format[i])
					count += id[j].func(args);
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
	return (count);
}
