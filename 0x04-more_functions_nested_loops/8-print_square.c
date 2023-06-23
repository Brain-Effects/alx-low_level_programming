#include "main.h"

/**
 * print_square - Prints a square followwed by a \n
 * @size: the size of the square
 * @#: prints the square
 *
 * Return: If size is 0 or less, the function should print a new line
 */
void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
		_putchar('#');
		}
		_putchar('\n');
	}
	}
	else
	{
	_putchar('\n');
	}
}
