#include "main.h"

/**
 * factorial - prints factorial og given numbers
 * @n: number
 *
 * Return: integer 1 if sucess 0 otherwise
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}
