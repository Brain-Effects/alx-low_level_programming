#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: string to encode
 *
 * Return: pointer to resulting string
 */
char *rot13(char *s)
{
	int i;
	char *p;

	for (i = 0; s[i] != '\0'; i++)
	{
	p = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
	{
		s[i] = p[s[i] - 'A'];
	}
	}

	return (s);
}
