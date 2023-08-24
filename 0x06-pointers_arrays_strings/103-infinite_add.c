#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: The first number
 * @n2: The second number
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result, or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len_n1 = 0, len_n2 = 0, carry = 0, sum = 0;
	int i, j, k;

	while (n1[len_n1] != '\0')
		len_n1++;
	while (n2[len_n2] != '\0')
		len_n2++;

	if (len_n1 > size_r || len_n2 > size_r)
		return (0);

	i = len_n1 - 1;
	j = len_n2 - 1;
	k = size_r - 1;
	r[k] = '\0';

	while (i >= 0 || j >= 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		r[k] = (sum % 10) + '0';

		i--;
		j--;
		k--;
	}

	if (carry)
	{
		if (size_r <= len_n1 + 1 || size_r <= len_n2 + 1)
			return (0);
		r[k] = carry + '0';
		return (r + k);
	}


	return (r + k + 1);
}
