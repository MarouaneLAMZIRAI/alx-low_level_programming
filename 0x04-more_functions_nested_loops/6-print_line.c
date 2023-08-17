#include "main.h"

/**
 * print_line - Prints a straight line in the terminal using _ character.
 * @n: The number of times the character _ should be printed.
 */
void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			_putchar('_');
	}
	_putchar('\n');
}
