#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
 * main - generates random valid passwords for 101-crackme
 *
 * Return: 0
 */
int main(void)
{
	int sum = 0;
	char c;

	srand(time(0));

	while (sum < 2772 - 127)
	{
	c = rand() % 127;
	if (c > 32)
	{
		_putchar(c);
		sum += c;
	}
	}
	_putchar(2772 - sum);

	return (0);
}
