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
 * binary_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, left = 0, right = size - 1;

	if (!array)
		return (-1);

	while (left <= right)
	{
	print_array(array + left, right - left + 1);
	mid = left + (right - left) / 2;
	if (array[mid] < value)
		left = mid + 1;
		else if (array[mid] > value)
		right = mid - 1;
	else
		return (mid);
	}

	return (-1);
}
