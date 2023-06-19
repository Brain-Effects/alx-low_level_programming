#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 123; i <= 789; i++)
	{
	if (i % 10 > i / 10 % 10 && i / 10 % 10 > i / 100)
	{
		putchar(i / 100 + '0');
		putchar(i / 10 % 10 + '0');
		putchar(i % 10 + '0');
	if (i < 789)
	{
		putchar(',');
		putchar(' ');
		}
	}
	}
		putchar('\n');

	return (0);
}

