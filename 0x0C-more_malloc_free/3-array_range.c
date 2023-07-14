#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum value to include in the array
 * @max: maximum value to include in the array
 *
 * Return: pointer to the newly created array, or NULL if the function fails
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, j;

	if (min > max)
	return (NULL);

	arr = malloc((max - min + 1) * sizeof(int));
	if (arr == NULL)
	return (NULL);

	for (i = min, j = 0; i <= max; i++, j++)
		arr[j] = i;

	return (arr);
}
