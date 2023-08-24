#include "main.h"

/**
 * rot13 - Entry
 * @str: string
 *
 * Return: str if success otherwise fail
 */

char *rot13(char *str)
{
	char *ptr = str;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13_alphbt[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	while (*ptr != '\0')
	{
	int found = 0;

	for (i = 0; i < 52; i++)
	{
	if (*ptr == alphabet[i])
	{
		*ptr = rot13_alphbt[i];
		found = 1;
		break;
	}
	}
	if (!found)
	{
		*ptr++ = *str;
	}
	str++;
	ptr++;
	}
	*ptr = '\0';
	return (ptr);
}
