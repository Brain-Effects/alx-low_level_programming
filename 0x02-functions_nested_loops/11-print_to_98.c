#include "unistd.h"
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting number
 *
 * Description: Numbers are separated by a comma and a space, and are printed
 * in order. The first printed number is n and the last printed number is 98.
 */

void print_to_98(int n)
{
	if (n <= 98)
	{
	for (; n < 98; n++)
	{
	print_number(n);
	_putchar(',');
	_putchar(' ');
	}
	}
	else
	{
	for (; n > 98; n--)
	{
	print_number(n);
	_putchar(',');
	_putchar(' ');
	}
	}
	print_number(n);
	_putchar('\n');
}

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
	div *= 10;

	for (j = div; j >= 1; j /= 10)
	_putchar(n / j % 10 + '0');
}
