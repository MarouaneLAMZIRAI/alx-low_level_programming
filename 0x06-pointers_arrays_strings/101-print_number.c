#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	int digit, sign;

	sign = 1;
	if (n < 0)
	{
		_putchar('-');
		sign = -1;
	}

	if (n / 10 != 0)
		print_number(sign * (n / 10));

	digit = n % 10;
	if (digit < 0)
		digit = -digit;

	_putchar('0' + digit);
}
