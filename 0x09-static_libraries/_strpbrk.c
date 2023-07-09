#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: set of bytes to search for
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;

	for (; *s; s++)
	{
	for (p = accept; *p; p++)
	{
	if (*s == *p)
		return (s);
		}
	}
	return (NULL);
}
