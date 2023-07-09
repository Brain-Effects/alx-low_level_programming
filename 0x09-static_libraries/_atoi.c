#include "main.h"
#include <stdio.h>

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (*s == ' ' || *s == '\t' || *s == '\n')
	s++;

	if (*s == '-')
	{
	sign = -1;
	s++;
	}
	else if (*s == '+')
	s++;

	while (*s >= '0' && *s <= '9')
	{
	result = result * 10 + (*s - '0');
	s++;
	}

	return (sign * result);
}
