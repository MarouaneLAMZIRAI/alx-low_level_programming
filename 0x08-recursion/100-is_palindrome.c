#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The input string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return length;
}

/**
 * is_palindrome_helper - Recursive helper function to check for palindrome
 * @s: The string to check
 * @start: The starting index
 * @end: The ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return 1;

	if (s[start] != s[end])
		return 0;

	return is_palindrome_helper(s, start + 1, end - 1);
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = _strlen(s);
	return is_palindrome_helper(s, 0, length - 1);
}
