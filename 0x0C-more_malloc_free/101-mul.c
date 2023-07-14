#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *str)
{
	while (*str)
	{
	if (!isdigit(*str))
	return (0);
	str++;
	}
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	long int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atol(argv[1]);
	num2 = atol(argv[2]);
	result = num1 * num2;

	printf("%ld\n", result);
	return (0);
}
