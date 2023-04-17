#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int name_len, owner_len;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	name_len = strlen(name) + 1;
	dog->name = malloc(name_len * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	strncpy(dog->name, name, name_len);

	dog->age = age;

	owner_len = strlen(owner) + 1;
	dog->owner = malloc(owner_len * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	strncpy(dog->owner, owner, owner_len);

	return (dog);
}
