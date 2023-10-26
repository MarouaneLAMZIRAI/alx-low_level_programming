#include "main.h"

/**
 * flip_bits - Count the number of bits needed to flip to get from n to m
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int xor_result = n ^ m;

		while (xor_result > 0)
	{
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
