#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * init_dog - Initializes a struct object of type dog with the given parameters
 * @d: Pointer to the struct dog object to be initialized
 * @name: Pointer to a string representing the name of the dog
 * @age:  Float representing the age of the dog
 * @owner:  Pointer to a string representing the owner of the dog
 *
 * Return: void
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = malloc(strlen(name) + 1);
		if (d->name)
			strcpy(d->name, name);
		d->age = age;
		d->owner = malloc(strlen(owner) + 1);
		if (d->owner)
			strcpy(d->owner, owner);
	}
}

