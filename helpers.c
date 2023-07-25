#include "main.h"
/**
 * _strchr - searches for a char in string and returns pointer
 *to the found
 * @s: string to be searched
 * @c: character to be searched for
 * Return: pointer or NULL
 */

char *_strchr(char *s, char c)
{
	int i = 0;
	char *t = NULL;

	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}

	if (s[i] == c)
	{
		t = &s[i];
		return (t);
	}
	else
	{
		return (NULL);
	}
}
