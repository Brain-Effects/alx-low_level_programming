#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t **addrs;
	int i;

	if (head == NULL)
		exit(98);

	addrs = malloc(sizeof(listint_t *) * 1024);
	if (addrs == NULL)
		exit(98);

	while (head != NULL)
	{
	for (i = 0; i < (int)count; i++)
	{
	if (head == addrs[i])
		{
		printf("-> [%p] %d\n", (void *)head, head->n);
		free(addrs);
		return (count);
		}
	}

		printf("[%p] %d\n", (void *)head, head->n);
		addrs[count] = head;
		count++;
		head = head->next;
	}

	free(addrs);

	return (count);
}
