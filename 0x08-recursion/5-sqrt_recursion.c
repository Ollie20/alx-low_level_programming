#include "main.h"

int sqrt_helper(int n, int st, int ed);

/**
 * _sqrt_recursion - Entry
 * @n: integer
 *
 * Return: integer
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		return (n);
	}
	return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - Entry
 * @n: integer
 * @st: start
 * @ed: end
 *
 * Return: square root of a number (naturall)
 */
int sqrt_helper(int n, int st, int ed)
{
	int md = (st + ed) / 2;

	if (md * md == n)
	{
		return (md);
	}
	if (st >= ed)
	{
		return (-1);
	}
	if (md * md > n)
	{
		return (sqrt_helper(n, st, md - 1));
	}
	return (sqrt_helper(n, md + 1, ed));
}
