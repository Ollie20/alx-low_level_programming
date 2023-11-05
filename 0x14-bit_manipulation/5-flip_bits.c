#include "main.h"

/**
* flip_bits - counts the num of bits to flip
* @n: first num
* @m: second num
* Description: compare to ints a count the diferences in bits
* Return: the number of different bits
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;

	i = 0;
	n = n ^ m;
	while (n)
	{
		i += n & 1;
		n >>= 1;
	}
	return (i);
}
