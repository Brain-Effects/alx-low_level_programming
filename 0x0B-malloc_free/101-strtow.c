#include <stdlib.h>
#include "main.h"

/**
 * word_count - counts the number of words in a string
 * @str: string to count words in
 *
 * Return: number of words in str
 */
int word_count(char *str)
{
	int i, wc = 0, in_word = 0;

	for (i = 0; str[i]; i++)
	{
	if (str[i] != ' ' && !in_word)
	{
		wc++;
		in_word = 1;
	}
		else if (str[i] == ' ')
		in_word = 0;
	}

	return (wc);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words), or NULL if str == NULL,
 *         str == "", or if the function fails
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, wc, len;

	if (str == NULL || str[0] == '\0')
	return (NULL);

	wc = word_count(str);
	if (wc == 0)
	return (NULL);

	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
	return (NULL);

	for (i = 0, k = 0; i < wc; i++)
	{
	while (str[k] == ' ')
		k++;

	for (j = k, len = 0; str[j] && str[j] != ' '; j++)
		len++;

	words[i] = malloc(sizeof(char) * (len + 1));
	if (words[i] == NULL)
	{
		for (j = 0; j < i; j++)
		free(words[j]);
		free(words);
		return (NULL);
	}

		for (j = 0; j < len; j++, k++)
		words[i][j] = str[k];
		words[i][j] = '\0';
	}

	words[i] = NULL;

	return (words);
}
