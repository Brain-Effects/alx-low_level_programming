#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to resulting string
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4300711";

	for (i = 0; s[i] != '\0'; i++)
	{
	for (j = 0; letters[j] != '\0'; j++)
	{
		if (s[i] == letters[j])
		{
		s[i] = numbers[j / 2];
		}
	}
	}

	return (s);
}
