#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: pointer to the first character of the string
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
	length++;
	return (length);
}
