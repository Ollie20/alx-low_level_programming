#include "main.h"
/**
* print_binary - function to binary rep of num
* @n: num to print in binary
* Description: code to convert decimal to binary
* Return: no return
*/
void print_binary(unsigned long int n)
{
	int flag = 0;
	unsigned long int mask = 1;

	mask <<= 63;
	if (n == 0)
		_putchar('0');

	while (mask > 0)
	{
		if ((n & mask) == 0 && flag == 1)
			_putchar('0');
		if ((n & mask) != 0)
		{
			_putchar('1');
			flag = 1;
		}

		mask = mask >> 1;
	}
}
