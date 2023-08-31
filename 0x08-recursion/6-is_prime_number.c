#include "main.h"
int is_prime_helper(int n, int divider);
/**
 * is_prime_number - Entry
 * @n: number
 *
 * Return: 1 if prime 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (is_prime_helper(n, 2));
}
/**
 * is_prime_helper - Entry
 * @n: number
 * @divider: checker
 *
 * Return: 1 if prime 0 otherwise
 */
int is_prime_helper(int n, int divider)
{
	if (divider >= n)
	{
		return (1);
	}
	if (n % divider == 0)
	{
		return (0);
	}
	return (is_prime_helper(n, divider + 1));
}
