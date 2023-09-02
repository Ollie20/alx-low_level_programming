#include "main.h"
#include <stdio.h>

/**
 * main - Entry
 * @argc: counter
 * @argv: pointer to char
 *
 * Return: integer
 */
int main(int __attribute__((unused))argc, char *argv[])
{
	int i;

	for (i = 0; argv[0][i] != '\0'; i++)
	{
		putchar(argv[0][i]);
	}
	putchar('\n');
	return (0);
}
