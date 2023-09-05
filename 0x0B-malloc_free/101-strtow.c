#include <stdlib.h>
#include "main.h"

/**
 * count_words - Count the number of words in a string
 * @str: The input string
 *
 * Return: Number of words
 */
int count_words(char *str)
{
	int i, words = 0, in_word = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && in_word == 1)
		{
			in_word = 0;
		}
		else if (str[i] != ' ' && in_word == 0)
		{
			in_word = 1;
			words++;
		}
	}
	return (words);
}

/**
 * copy_word - Copy a word from the string to a new string
 * @str: The input string
 * @start: Start index of the word
 * @end: End index of the word
 *
 * Return: Pointer to the new string containing the word
 */
char *copy_word(char *str, int start, int end)
{
	char *word;
	int i, j = 0;

	word = malloc(sizeof(char) * (end - start + 2));
	if (word == NULL)
		return (NULL);

	for (i = start; i <= end; i++)
	{
		word[j] = str[i];
		j++;
	}
	word[j] = '\0';
	return (word);
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j = 0, in_word = 0, start = 0, end = 0, words;
	char **word_array;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	word_array = malloc(sizeof(char *) * (words + 1));
	if (word_array == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && in_word == 1)
		{
			end = i - 1;
			word_array[j] = copy_word(str, start, end);
			if (word_array[j] == NULL)
			{
				while (j >= 0)
				{
					free(word_array[j]);
					j--;
				}
				free(word_array);
				return (NULL);
			}
			j++;
			in_word = 0;
		}
		else if (str[i] != ' ' && in_word == 0)
		{
			start = i;
			in_word = 1;
		}
	}

	if (in_word == 1)
	{
		end = i - 1;
		word_array[j] = copy_word(str, start, end);
		if (word_array[j] == NULL)
		{
			while (j >= 0)
			{
				free(word_array[j]);
				j--;
			}
			free(word_array);
			return (NULL);
		}
		j++;
	}
	word_array[j] = NULL;
	return (word_array);
}
