#include <stdio.h>
#include "main.h"

/**
 * printnumber - Entry
 * @num: number
 *
 */
void printnumber(int num)
{
	if (num > 9)
	{
		printnumber(num / 10);
	}
	putchar('0' + (num % 10));
}

/**
 * main - Entry
 * @argc: counter
 * @argv: char pointer
 *
 * Return: integer
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
	int num_arg = argc - 1;

	if (num_arg < 0)
	{
		num_arg = 0;
	}
	if (num_arg == 0)
	{
		putchar('0');
	} else
	{
		printnumber(num_arg);
	}
	putchar('\n');
	return (0);
}
