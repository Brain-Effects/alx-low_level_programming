#include "main.h"

/**
 * _puts - Prints the s string followed by a new line
 * @s: The string that needs to be printed
 *
 * Return: Always 0.
 */
void _puts(char *s)
{
	while (*s)
	{
	_putchar(*s);
	s++;
	}
	_putchar('\n');
}
