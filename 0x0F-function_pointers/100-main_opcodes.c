#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 if successful, 1 if the number of arguments is wrong,
 * or 2 if the number of bytes is negative
 */
int main(int argc, char *argv[])
{
	int n, i;
	char *p;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}

	p = (char *)main;
	for (i = 0; i < n; i++)
	{
		printf("%02hhx", p[i]);
		if (i < n - 1)
		printf(" ");
	}
	printf("\n");

	return (0);
}
