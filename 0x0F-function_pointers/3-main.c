#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

int (*get_op_func(char *s))(int, int);
/**
 * main -  Entry
 * @argc: argument
 * @argv: array
 *
 * Return: 0 if success otherwise fail
 */
int main(int argc, char *argv[])
{
	int number1;
	int number2;
	int answer;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	number1 = atoi(argv[1]);
	number2 = atoi(argv[3]);

	op_func = get_op_func(argv[2]);

	if (op_func == NULL)
	{
		printf("Error\n");
		return (99);
	}
	if ((*argv[2] == '/' || *argv[2] == '%') && number2 == 0)
	{
		printf("Error\n");
		return (100);
	}
	answer = op_func(number1, number2);
	printf("%d\n", answer);
	return (0);
}
