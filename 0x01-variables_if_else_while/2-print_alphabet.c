#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char c;

	for(c = 'a'; c <= 'z'; c++)
{
	putchar(c);
	if(c == 'v')
	putchar('x');
}
	putchar('\n');

	return (0);
}

