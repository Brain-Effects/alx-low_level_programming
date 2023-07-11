#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
  * main - adds positive numbers
  * @argc: The numbers to be added
  * @argv: The numbers to be printed
  *
  * Return: 0 otherwise 1 If one of the number contains symbols
  */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i, j;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
		if (!isdigit(argv[i][j]))
		{
			printf("Error\n");
			return (1);
		}
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
