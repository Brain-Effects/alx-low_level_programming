#include <stdio.h>
#include <stdlib.h>

/**
  * main - Prints out the result of the multiplication followed by a new line
  * @argc: The integer to be multipied
  * @argv: The string to be multiplied
  *
  * Return: 0 otherwise 1 if the number of arguments is not equal to 3
  */
int main(int argc, char *argv[])
{
	int num1, num2, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	product = num1 * num2;

		printf("%d\n", product);
		return (0);
}
