#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *rot13(char *str)
{
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (input[j] != '\0')
		{
			if (str[i] == input[j])
			{
				str[i] = output[j];
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
