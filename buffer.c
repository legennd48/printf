#include "main.h"

/**
 * make_buff - makes a buffer to hold strings temporarily until the are
 * ready for printing
 * Return: pointer to new buffer
 */


char *make_buffer(void)
{
	char *buffer;

	buffer = malloc(1024 * sizeof(char)); /* allocates the req buffer */
	if (buffer == NULL)
		return (NULL);

	return (buffer);
}


/**
 * putstring - takes a pointer to buffer as argument, prints and frees it
 * @buffer: buffer argumen that holds printables
 * @lent: lenght of the string to be printed
 * @args: va_list argument
 */

void putstring(char *buffer, int lent, va_list args)
{
	char *temp;

	temp = reallocc(buffer, lent); /* shaves away excess memory */

	write(1, temp, lent); /* just like putchar */

	free(temp);

}
