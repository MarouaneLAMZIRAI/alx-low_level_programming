#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *leet(char *str)
{
	char leet_table[] = "aeotlAEOTL";
	char leet_replacements[] = "4307143071";
	int i, j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (leet_table[j] != '\0')
		{
			if (str[i] == leet_table[j])
				str[i] = leet_replacements[j];
			j++;
		}
		i++;
	}

	return (str);
}
