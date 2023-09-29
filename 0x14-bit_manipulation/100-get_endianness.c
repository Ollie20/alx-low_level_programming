#include "main.h"

/**
* get_endianness - get the endiannes of system
* Description: get the endiannes of the system
* Return: 1 if little endian  0 in big endian.
*/

int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;

	if (*c)
		return (1);
	return (0);
}
