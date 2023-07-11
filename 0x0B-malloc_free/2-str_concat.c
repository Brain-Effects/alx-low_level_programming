#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the newly allocated space in memory which contains
 *         the contents of s1, followed by the contents of s2,
 *         and null terminated,
 *         or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
		for (len1 = 0; s1[len1]; len1++)
		;
	if (s2 != NULL)
		for (len2 = 0; s2[len2]; len2++)
		;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];

	concat[i] = '\0';

	return (concat);
}
