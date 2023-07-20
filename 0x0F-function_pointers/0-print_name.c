#include <stdio.h>
#include <ctype.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: the name to print
 * @f: the function to use to print the name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

/**
 * print_upper - prints a name in uppercase
 * @name: the name to print
 *
 * Return: void
 */
void print_upper(char *name)
{
	int i = 0;

	while (name[i])
	{
		putchar(toupper(name[i]));
		i++;
	}
	putchar('\n');
}
