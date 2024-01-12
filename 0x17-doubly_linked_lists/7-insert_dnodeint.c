#include <stdlib.h>
#include "lists.h"

/**
 * create_new_node - Creates a new node for a dlistint_t list.
 * @n: The integer to be included in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *create_new_node(int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL) return NULL;
    new_node->n = n;
    return new_node;
}
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the head of the list.
 * @idx: The index of the list where the new node should be added. Index starts at 0.
 * @n: The integer to be included in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL || (idx != 0 && *h == NULL)) return NULL;
	new_node = create_new_node(n);
	if (new_node == NULL) return NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h != NULL) (*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	while (temp && ++i < idx) temp = temp->next;
	if (temp == NULL) { free(new_node); return NULL; }

	new_node->next = temp->next;
	new_node->prev = temp;
	if (temp->next != NULL) temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
