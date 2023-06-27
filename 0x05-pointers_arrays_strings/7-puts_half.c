#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i, n, length = 0;

	while (str[length] != '\0')
	{
	length++;
	}

	if (length % 2 == 0)
	{
	n = length / 2;
	}
	else
	{
	n = (length - 1) / 2;
	}

	for (i = n; i < length; i++)
	{
	_putchar(str[i]);
	}
}
