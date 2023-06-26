#include <stdio.h>

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: pointer to the first character of the string
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str)
	putchar(*str++);
	putchar('\n');
}
