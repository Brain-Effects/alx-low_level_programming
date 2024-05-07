#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, idx;
	listint_t *left, *right;

	if (!list)
		return (NULL);

	/* Calculate jump size */
	jump = sqrt(size);

	/* Find the block where value is present */
	left = list;
	right = list;
	while (right->index < size - 1 && right->n < value)
	{
		left = right;
		for (idx = 0; idx < jump && right->next; idx++)
		right = right->next;
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left->index, right->index);

	/* Perform linear search in the selected block */
	while (left->index <= right->index && left->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		if (left->n == value)
		return (left);
		left = left->next;
	}

	return (NULL);
}
