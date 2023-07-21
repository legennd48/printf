/**
 * _putchar - prints a character to stdout
 *@c: character to be printed
 *
 * Return: 1 on success
 */
#include <unistd.h>
int _putchar(char c)
{
	return (write(1, &c, 1));
}
