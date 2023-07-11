#include <stdio.h>

/**
  * main - Prints all arguments recieved from the first one line by line
  * @argc: The arguments recieved
  * @argv: The string that needs to be printed
  *
  * Return: Always 0 (Success)
  */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
