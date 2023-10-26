#include "main.h"

/**
 * binary_to_uint - Convert a binary number to an unsigned int
 * @b: A pointer to a string containing 0 and 1 characters
 *
 * Return: The converted number, or 0 if there are characters
 * other than 0 or 1 in the string or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		num = (num * 2) + (*b - '0');
		b++;
	}
	return (num);
}
