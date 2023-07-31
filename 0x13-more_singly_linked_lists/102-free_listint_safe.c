#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp, *next;
	const listint_t **addrs;
	int i;

	if (h == NULL || *h == NULL)
		return (0);

	addrs = malloc(sizeof(listint_t *) * 1024);
	if (addrs == NULL)
		exit(98);

	temp = *h;

	while (temp != NULL)
	{
	for (i = 0; i < (int)count; i++)
		{
		if (temp == addrs[i])
		{
		*h = NULL;
		free(addrs);
		return (count);
		}
	}

		addrs[count] = temp;
		count++;
		next = temp->next;
		free(temp);
		temp = next;
	}

	*h = NULL;
	free(addrs);

	return (count);
}
