#include "main.h"

/**
 * print_line - Draws a straight line in the terminal
 * @n: Is the number of times the charater should be printed
 *
 * Return: If n is 0 or less, the function should print \n
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
	_putchar('_');
	}
	_putchar('\n');
}
