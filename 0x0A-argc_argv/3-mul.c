#include "main.h"

void printnum(int num);

/**
 * main - Entry
 * @argc: counter
 * @argv: char pointer
 *
 * Return: integer
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
	int number1 = 0;
	int number2 = 0;
	int i;
	int res;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		return (1);
	}

	for (i = 0; argv[1][i] != '\0'; i++)
	{
		number1 = number1 * 10 + (argv[1][i] - '0');
	}
	for (i = 0; argv[2][i] != '\0'; i++)
	{
		number2 = number2 * 10 + (argv[2][i] - '0');
	}

	res = number1 * number2;

	printnum(res);
	_putchar('\n');
	return (0);
}

/**
 * printnum - Entry
 * @num: number
 *
 */
void printnum(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num / 10)
	{
		printnum(num / 10);
	}
	_putchar((num % 10) + '0');
}
