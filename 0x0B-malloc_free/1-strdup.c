#include "main.h"
#include <stdlib.h>

/**
 * _strdup- Returns a pointer to a newly allocated space in memory
 * @str: string
 *
 * Return: character pointer
 */
char *_strdup(char *str)
{
	char *cpy;
	unsigned int i;
	unsigned int length = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[length] != '\0')
	{
		length++;
	}
	cpy = (char *)malloc((length + 1) * sizeof(char));

	if (cpy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		cpy[i] = str[i];
	}
	return (cpy);
}
