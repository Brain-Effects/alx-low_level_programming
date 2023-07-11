#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, or NULL if ac == 0, av == NULL,
 *         or if it fails.
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, len = 0;

	if (ac == 0 || av == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
		len++;

	str = malloc(sizeof(char) * (len + ac + 1));
	if (str == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
		str[k] = av[i][j];
		str[k++] = '\n';
	}

	str[k] = '\0';

	return (str);
}
