#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	int i, j, div;

	if (n < 0)
	{
	_putchar('-');
	n = -n;
	}

	div = 1;
	for (i = n; i >= 10; i /= 10)
	{
	div *= 10;
	}

	for (j = div; j >= 1; j /= 10)
	{
	_putchar('0' + n / j);
	n %= j;
	}
}
