#include "main.h"

/**
 * times_table - Prints the 9 times table.
 *
 * Return: rows and columns
 */
void times_table(void)
{
	int row, column, result;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			result = row * column;

			if (column == 0)
			{
				_putchar('0');
			}
			else if (result <= 9)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(result + '0');
			}
			else
			{
				_putchar(' ');
				_putchar(result / 10 + '0');
				_putchar(result % 10 + '0');
			}

			if (column < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
