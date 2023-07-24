#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * make_buffer - makes a buffer to hold strings temporarily until they are
 * ready for printing
 * Return: pointer to new buffer
 */


char *make_buffer(void)
{
	char *buffer;

	buffer = malloc(1024 * sizeof(char)); /* allocates the req buffer */
	if (buffer == NULL)
		return (NULL);

	buffer[0] = '\0';

	return (buffer);
}


/**
 * putstring - takes a pointer to buffer as argument, prints and frees it
 * @buffer: buffer argumen that holds printables
 * @lent: lenght of the string to be printed
 */

void putstring(char *buffer, int lent)
{
	/*char *temp;*/

	/*temp = realloc(buffer, lent); shaves away excess memory */

	write(1, buffer, lent); /* just like putchar */

	free(buffer);
}


/**
*_strlen - returns the length of a string
*@s: string to be checked
*Return: length of string
*/

int _strlen(char *s)
{
	int lent = 0;

	while (*s != '\0')
	{
		s++;
		lent++;
	}
	return (lent);
}
