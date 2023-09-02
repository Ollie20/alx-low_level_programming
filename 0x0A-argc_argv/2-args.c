#include "main.h"

/**
 * main - Entry
 * @argc: counter
 * @argv: char pointer
 *
 * Return: integer
 */
int main(int argc, char *argv[])
{
	int i;
	char *arg;

	for (i = 0; i < argc; i++)
	{
		arg = argv[i];

		while (*arg != '\0')
		{
			_putchar(*arg);
			arg++;
		}
		_putchar('\n');
	}
	return (0);
}
