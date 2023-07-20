#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - prints a char
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
	printf("%s", str);
	else
	printf("(nil)");
}

/**
 * print_all - prints anything
 * @format: the format string
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *sep = "";

	print_t prints[] = {
	{'c', print_char},
	{'i', print_int},
	{'f', print_float},
	{'s', print_string},
	{0, NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (prints[j].c)
	{
		if (prints[j].c == format[i])
	{
		printf("%s", sep);
		prints[j].f(args);
		sep = ", ";
		break;
	}
		j++;
	}
		i++;
	}
	va_end(args);

	printf("\n");
}
