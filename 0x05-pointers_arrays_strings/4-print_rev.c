#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the first character of the string
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;
	while (s[length])
	length++;
	while (length--)
	putchar(s[length]);
	putchar('\n');
}
