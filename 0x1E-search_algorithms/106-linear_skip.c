#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left = list, *right = list;

	if (!list)
		return (NULL);

	/* Find the block where value is present */
	while (right->express && right->express->n < value)
	{
		left = right;
		right = right->express;
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
	}

	if (right->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", right->express->index, right->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n", left->index, right->express->index);
	}
		else
	{
		left = right;
		while (right->next)
		right = right->next;
		printf("Value found between indexes [%lu] and [%lu]\n", left->index, right->index);
	}

	/* Perform linear search in the selected block */
	while (left && left->index <= right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		if (left->n == value)
		return (left);
		left = left->next;
	}

	return (NULL);
}
