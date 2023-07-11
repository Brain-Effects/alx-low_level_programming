#include <stdio.h>

/**
  * main - prints out the number of things put on the command line
  * @argc: The integer value to be printed
  * @argv: The string that needs be printed
  *
  * Return: Always 0 (Success)
  */

int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
