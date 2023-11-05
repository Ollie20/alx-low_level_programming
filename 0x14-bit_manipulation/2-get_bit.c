#include "main.h"

/**
* get_bit - return value of bit
* @n: num
* @index: the position to read the bit
* Description: code to return 1 bit
* Return: the value of the bit
*/

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit;

	if (index > 64)
		return (-1);

	bit = n >> index;

	return (bit & 0x1);
}
