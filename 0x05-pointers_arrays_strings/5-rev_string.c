#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the first character of the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;

	int i;

	while (s[length])
	length++;

	for (int i = 0; i < length / 2; i++)
	{
	char temp = s[i];

	s[i] = s[length - i - 1];
	s[length - i - 1] = temp;
	}
}
