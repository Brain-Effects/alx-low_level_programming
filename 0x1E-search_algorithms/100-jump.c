#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if value is not present
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, left = 0, right;

	if (!array)
		return (-1);

	/* Calculate jump size */
	jump = sqrt(size);

	/* Find the block where value is present */
	while (left < size && array[left] <= value)
	{
	right = fmin(size - 1, left + jump);
	printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		if (array[left] <= value && array[right] >= value)
		break;
		left += jump;
	}

	if (left >= size || array[left] > value)
		return (-1);

	/* Perform linear search in the selected block */
	right = fmin(size - 1, right);
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	while (left <= right && array[left] <= value)
	{
		if (array[left] == value)
		return (left);
		left++;
	}

	return (-1);
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
