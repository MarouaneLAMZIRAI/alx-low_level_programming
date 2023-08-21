#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords for the 101-crackme program
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, sum = 0, diff = 2772 - 122;

	srand(time(0));

	while (sum < 2772)
	{
		i = rand() % 62;
		if (i < 10)
		{
			putchar(i + '0');
			sum += i;
		}
		else if (i < 36)
		{
			putchar(i - 10 + 'A');
			sum += i - 10;
		}
		else
		{
			putchar(i - 36 + 'a');
			sum += i - 36;
		}
	}

	if (sum > 2772)
	{
		putchar(diff);
	}

	return (0);
}
