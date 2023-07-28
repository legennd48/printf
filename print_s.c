/**
 * print_s - print a string to standard output
 * @args: argunment parameters
 *
 * Return: number of characters printed on success
 */
#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

int print_s(va_list args)
{
	int i = 0, count = 0;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		count++;
		i++;
	}

	/*_putchar('\n');*/
	return (count);
}
/**
 * print_S - prints a string and its non-printable character
 * ASCII value.
 * @args: argument parameters
 *
 * Return: count of characters on Success
 */
int print_S(va_list args)
{
	char *s;
	int i = 0, count = 0;

	s = va_arg(args, char *);
	/* Handling "NULL" edge case */
	if (!s[i])
		s = "";

	while (s[i])
	{
		if (s[i] >= 32 && s[i] < 127)
			count += _putchar(s[i]);
		else
		{
			count += print_non_printable((unsigned char)s[i]);
		}
		i++;
	}
	return (count);
}

/**
 * print_non_printable - prints the non_prinatble portion of a
 * string in ASCII code
 * @ascii: code to be printed
 *
 * Return: number of characters printed
 */

int print_non_printable(unsigned char ascii)
{
	unsigned char lower_nibble = ascii % 16;
	unsigned char upper_nibble = ascii / 16;
	char hex_lower, hex_upper;
	char escape_sequence[4];

	if (lower_nibble < 10)
		hex_lower = lower_nibble + '0';
	else
		hex_lower = (lower_nibble - 10) + 'A';
	if (upper_nibble < 10)
		hex_upper = upper_nibble + '0';
	else
		hex_upper = (upper_nibble - 10) + 'A';
	escape_sequence[0] = '\\';
	escape_sequence[1] = 'x';
	escape_sequence[2] = hex_upper;
	escape_sequence[3] = hex_lower;
	return (write(1, escape_sequence, sizeof(escape_sequence)));
}
