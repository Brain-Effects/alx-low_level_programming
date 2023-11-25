#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	char flag = 0;

	if (n == 0) /* handle 0 explicitly */
	{
	printf("0");
	return;
	}

	/* create mask starting at highest bit */
	mask = 1UL << ((sizeof(n) * 8) - 1);

	while (mask)
	{
	if ((n & mask) == 0) /* if this bit is not set */
	{
	if (flag) /* print this bit if we have printed before */
		_putchar('0');
	}
		else
	{
		flag = 1; /* we have started printing */
		_putchar('1');
	}
		mask >>= 1; /* check next bit */
	}
}
