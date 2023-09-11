#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Represents information about a dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: This structure defines a dog's attributes.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Prototype for the init_dog function */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
