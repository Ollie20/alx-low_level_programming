#include "main.h"
#include <ctype.h>

/**
 * cap_string - Entry
 * @str: string
 *
 * Return: str if success otherwise if fail
 */
char *cap_string(char *str)
{
	int cap_t = 1;
	char *ptr = str;

	while (*ptr != '\0')
	{
	if (cap_t && islower(*ptr))
	{
		*ptr = toupper(*ptr);
	}
	if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == ',' ||
		*ptr == ';' || *ptr == '.' || *ptr == '!' || *ptr == '?' ||
		*ptr == '"' || *ptr == '(' || *ptr == ')' || *ptr == '{' ||
		*ptr == '}')
	{
		cap_t = 1;
	} else
	{
		cap_t = 0;
	}
	ptr++;
	}
	return (str);
}
