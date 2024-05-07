#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
		printf(", ");
		printf("%d", array[i]);
	}
		printf("\n");
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if value is not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t mid;

	if (!array || size == 0)
		return (-1);

	print_array(array, size);
	mid = (size - 1) / 2;
	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] < value)
		return (mid);
	else	
		return advanced_binary(array, mid + 1, value);
	}
		else if (array[mid] < value)
		return advanced_binary(array + mid + 1, size - mid - 1, value);
	else
		return advanced_binary(array, mid + 1, value);
}
