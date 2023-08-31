#include "main.h"
#include <string.h>
int is_palindrome_recursive();
/**
 * is_palindrome - Entry
 * @s: string
 *
 * Return: returns 1 if a string is palindrome 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	return (is_palindrome_recursive(s, 0, len - 1));
}
/**
 * is_palindrome_recursive - recursive func
 * @s: string
 * @strt: start of the string
 * @end: end of the string
 *
 * Return: 1 if palindrome and 0 otherwise
 */
int is_palindrome_recursive(char *s, int strt, int end)
{
	if (strt >= end)
	{
		return (1);
	}
	if (s[strt] != s[end])
	{
		return (0);
	}
	return (is_palindrome_recursive(s, strt + 1, end - 1));
}
