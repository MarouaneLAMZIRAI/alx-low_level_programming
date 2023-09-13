#include <stddef.h>

/**
 * array_iterator - execute a func given as a param on each element of an arr
 * @array: an array of integers
 * @size: the size of the array
 * @action: a pointer to the function to be executed on each element
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
		size_t i;

		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
