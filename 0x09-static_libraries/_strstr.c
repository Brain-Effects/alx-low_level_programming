#include "main.h"
#include <stdio.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to search for
 *
 * Return: pointer to the beginning of the located substring, or NULL if the
 * substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *p, *q;

	for (; *haystack; haystack++)
	{
	for (p = haystack, q = needle; *q && *p == *q; p++, q++)
		;
		if (!*q)
		return (haystack);
	}
	return (0);
}
