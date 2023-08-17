#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int n = 612852475143;
	unsigned long int i, maxPrime;

	while (n % 2 == 0)
	{
		n /= 2;
	}
	maxPrime = (n < 2) ? 2 : n;

	for (i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
			maxPrime = i;
		}
	}

	if (n > 2)
	{
		maxPrime = n;
	}

	printf("%lu\n", maxPrime);

	return (0);
}
