#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table you want to add or update the key/value to
 * @key: key is the key. key can not be an empty string
 * @value: value is the value associated with the key.
 * value must be duplicated. value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
	if (strcmp(temp->key, key) == 0)
	{
		free(temp->value);
		temp->value = strdup(value);
		return (temp->value != NULL);
	}
		temp = temp->next;
	}

	new_node = create_new_node(key, value);
	if (new_node == NULL)
	return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * create_new_node - creates a new hash node
 * @key: the key of the new node
 * @value: the value of the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
	return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}
