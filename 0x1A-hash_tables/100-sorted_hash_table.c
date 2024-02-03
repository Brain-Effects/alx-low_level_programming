#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 * If something went wrong, returns NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
	return (NULL);

	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	new_table->array[i] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: hash table you want to add or update the key/value to
 * @key: key is the key. key can not be an empty string
 * @value: value is the value associated with the key.
 * value must be duplicated. value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL, *node = NULL;
	unsigned long int index;

	if (!ht || !key || !*key || !value)
	return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
	if (!strcmp(node->key, key))
	{
		free(node->value);
		node->value = strdup(value);
		return (1);
	}
		node = node->next;
	}

	new_node = create_new_node(key, value);
	if (!new_node)
	return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	insert_node(ht, new_node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table you want to look into
 * @key: key you are looking for
 *
 * Return: value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
	return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (!strcmp(node->key, key))
		return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
	return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node)
		printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
	return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node)
		printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (!ht)
	return;

	node = ht->shead;
	while (node)
	{
	temp = node->snext;
	free(node->key);
	free(node->value);
	free(node);
	node = temp;
	}

	free(ht->array);
	free(ht);
}

/**
 * create_new_nodes - creates a new hash node
 * @key: the key of the new node
 * @value: the value of the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node =  malloc(sizeof(shash_node_t));

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

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * insert_node - inserts a node into the sorted linked list
 * @ht: the hash table
 * @new_node: the new node to insert
 */
void insert_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *node;

	node = ht->shead;
	while (node && strcmp(node->key, new_node->key) < 0)
	node = node->snext;

	new_node->sprev = node->sprev;
	new_node->snext = node;

	if (node->sprev)
	node->sprev->snext = new_node;
	else
	ht->shead = new_node;

	node->sprev = new_node;
}
