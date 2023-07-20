#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 *
 * Return: a pointer to the new dog, or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_name, *new_owner;

	new_dog = malloc(sizeof(dog_t));
	if (!new_dog)
	return (NULL);

	new_name = malloc(strlen(name) + 1);
	if (!new_name)
	{
		free(new_dog);
		return (NULL);
	}
	strcpy(new_name, name);
	
	new_owner = malloc(strlen(owner) + 1);
	if (!new_owner)
	{
		free(new_name);
		free(new_dog);
		return (NULL);
	}
	strcpy(new_owner, owner);

	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;

	return (new_dog);
}
