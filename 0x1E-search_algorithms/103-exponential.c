#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if value is not present
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, left = 0, right = size - 1;
	size_t i = 0;

	if (!array)
		return (-1);

	printf("Searching in array: ");
		for (i = 0; i < size; i++)
		printf("%d ", array[i]);
		printf("\n");

	while (left <= right)
	{
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

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (!array)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	return binary_search(array + bound / 2, min(bound + 1, size) - bound / 2, value);
}

/**
 * min - Returns the minimum of two values
 * @a: The first value
 * @b: The second value
 *
 * Return: The minimum of @a and @b
 */
size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}
