#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to be printed
 */
void print_number(int n)
{
	int divisor = 1;
	int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}

	while (num / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		_putchar(num / divisor + '0');
		num %= divisor;
		divisor /= 10;
	}
}
