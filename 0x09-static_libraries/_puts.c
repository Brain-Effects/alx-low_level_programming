#include "main.h"

/**
 * main - check the code
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
