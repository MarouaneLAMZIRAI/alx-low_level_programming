#include "main.h"

/**
 * print_alphabet- this print alphabets
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		write(1, &letter, 1);
		letter++;
	}
	write(1, "\n", 1);
}
