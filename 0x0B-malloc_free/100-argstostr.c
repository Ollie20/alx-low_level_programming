#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates
 * @ac: count
 * @av: vector
 *
 * Return: pointer
 */
char *argstostr(int ac, char **av)
{
	int tl, i, j, l, idx;
	char *arg, *res;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		arg = av[i];

		l = 0;
		while (arg[l] != '\0')
		{
			l++;
		}
		tl += l + 1;
	}
	res = (char *)malloc((tl + 1) * sizeof(char));
	if (res == NULL)
	{
		return (NULL);
	}
	idx = 0;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		j = 0;
		while (arg[j] != '\0')
		{
			res[idx] = arg[j];
			idx++;
			j++;
		}
		res[idx] = '\n';
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
