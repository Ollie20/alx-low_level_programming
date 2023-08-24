#include "main.h"
#include <ctype.h>

/**
 * string_toupper - Entry
 * @str: string
 *
 * Return: str if success otherwise if fail
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
	if (islower(*ptr))
	{
		*ptr = toupper(*ptr);
	}
	ptr++;
	}
	return (str);
}
