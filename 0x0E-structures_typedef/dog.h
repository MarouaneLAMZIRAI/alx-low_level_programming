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

/* Prototype for the print_dog function */
void print_dog(struct dog *d);

/* Define a new type dog_t as an alias for struct dog */
typedef struct dog dog_t;

/* Prototype for the new_dog function */

dog_t *new_dog(char *name, float age, char *owner);

/* Prototype for the free_dog function */
void free_dog(dog_t *d);

#endif /* DOG_H */
