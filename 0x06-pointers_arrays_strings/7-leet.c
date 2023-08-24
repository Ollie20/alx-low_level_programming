#include "main.h"

/**
 * leet - Entry
 * @str: string
 *
 * Return: str if success and otherwise if fail
 */
char *leet(char *str)
{
	char *ptr = str;
	char leet_letters[] = "aAeEoOtTlL";
	char leet_digits[] = "4433007711";
	int i;

	while (*ptr != '\0')
	{
	for (i = 0; i < 10; i++)
	{
	if (*ptr == leet_letters[i])
	{
		*ptr = leet_digits[i];
		break;
	}
	}
	ptr++;
	}
	return (str);
}
