#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * alloc_grid - Entry
 * @width: width
 * @height: height
 *
 * Return: char pointer
 */
int **alloc_grid(int width, int height)
{
	int i;
	int j;
	int k;
	int **grid;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(width * sizeof(int));

		if (grid[i] == NULL)
		{
			for (k = i; k >= 0; k--)
			{
				free(grid[k]);
			}
		free(grid);
		return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
	return (grid);
}
