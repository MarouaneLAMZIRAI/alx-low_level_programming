#include "main.h"

/**
 * wildcmp_helper - Recursive helper function to compare strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 1 if identical, otherwise 0
 */
int wildcmp_helper(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp_helper(s1, s2 + 1));

		return (wildcmp_helper(s1 + 1, s2) || wildcmp_helper(s1, s2 + 1));
	}

	if (*s1 == *s2)
		return (wildcmp_helper(s1 + 1, s2 + 1));

	return (0);
}

/**
 * wildcmp - Compares two strings with wildcard pattern
 * @s1: First string
 * @s2: Second string with wildcard pattern
 *
 * Return: 1 if identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_helper(s1, s2));
}
