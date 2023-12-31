#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Makes an arr of chars and init it with a specif char
 * @size: The size of the array
 * @c: The character to initialize the array with
 *
 * Return: If size is 0 or the function fails - NULL.
 *         Otherwise - a pointer to the array.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
