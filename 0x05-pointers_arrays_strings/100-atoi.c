#include "main.h"
#include "unistd.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value of string
 */
int _atoi(char *s)
{
	int i, sign = 1;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
	if (s[i] == '-')
	{
		sign *= -1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
	}
	else if (num > 0)
	{
		break;
	}
	}

	return (sign * num);
}
