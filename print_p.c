/**
 * print_p - prints the value of a pointer
 * @args: argument pointer
 *
 * Return: number of characters printed
 */
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
int print_p(va_list args)
{
	void *p;
	int count = 0, i = 0;
	char *s;

	p = va_arg(args, void *);

	if (p == NULL)
	{
		s = "(nil)";
		while (s[i])
		{
			count += _putchar(s[i]);
			i++;
		}
		return (count);
	}
	count += print_memory_address(p);
	return (count);
}
/**
 * print_memory_address - prints address stored in a pointer
 * @p: pointer whose value is to be printed
 *
 * Return: number of character printed on Success
 */
int print_memory_address(void *p)
{
	unsigned long addr, mask, shift, digit;
	int count = 0;
	char *s;
	unsigned int i, j;
	int non_zero = 0;

	if (p == NULL)
	{
		s = "(null)";
		while (s[j])
		{
			count += _putchar(s[j]);
			j++;
		}
		return (count);
	}
	mask = 0xF;
	addr = (unsigned long)p;
	shift = (sizeof(void *) * 8) - 4;

	count += _putchar('0');
	count += _putchar('x');
	for (i = 0; i < (sizeof(void *) * 2); i++)
	{
		digit = (addr >> (shift)) & mask;
		if (digit != 0 || non_zero == 1)
		{
			if (digit < 10)
				count += _putchar('0' + digit);
			else
				count += _putchar('a' + digit - 10);
			non_zero = 1;
		}
		shift -= 4;
	}
	if (count == 2)
		count += _putchar('0');
	return (count);
}
