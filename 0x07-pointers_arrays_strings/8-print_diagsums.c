#include "main.h"
#include "stdlib.h"
#include "unistd.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_number - prints an integer
 * @n: integer to print
 */
void print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
	_putchar('-');
	num = -n;
	}

	if (num / 10)
	print_number(num / 10);

	_putchar((num % 10) + '0');
}

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the matrix
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
	sum1 += a[(size + 1) * i];
	sum2 += a[(size - 1) * (i + 1)];
	}

	print_number(sum1);
	_putchar(',');
	_putchar(' ');
	print_number(sum2);
	_putchar('\n');
	{
	return (void)
}
}
