#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;

	/* If the first byte (lowest address) is 1, it's little endian */
	if (*c)
		return (1);
	return (0);
}
