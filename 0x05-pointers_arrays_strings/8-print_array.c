#include <unistd.h>
#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: array to print
 * @n: number of elements to print
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	int i, j, num;
	char c;

	for (i = 0; i < n; i++)
	{
	num = a[i];
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	j = 1;
	while (num / j > 9)
	{
		j *= 10;
	}
	while (j > 0)
	{
		c = '0' + num / j;
		write(1, &c, 1);
		num %= j;
		j /= 10;
	}
	if (i != n - 1)
	{
		write(1, ", ", 2);
	}
	}
	write(1, "\n", 1);
}
