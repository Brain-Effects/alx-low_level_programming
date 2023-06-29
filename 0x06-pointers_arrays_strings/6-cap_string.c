#include"main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to resulting string
 */
char *cap_string(char *s)
{
	int i;
	char prev;

	for (i = 0, prev = ' '; s[i] != '\0'; i++, prev = s[i - 1])
	{
	if ((prev == ' ' || prev == '\t' || prev == '\n' || prev == ',' ||
		prev == ';' || prev == '.' || prev == '!' || prev == '?' ||
		prev == '"' || prev == '(' || prev == ')' || prev == '{' ||
		prev == '}') && (s[i] >= 'a' && s[i] <= 'z'))
	{
		s[i] -= 32;
	}
	}

	return (s);
}
