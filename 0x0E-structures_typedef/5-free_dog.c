#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog structure and its components.
 * @d: A pointer to the dog structure to free.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
