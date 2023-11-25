#include <stdio.h>
#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to change
 * @index: index at which to set bit
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
/* check if index is greater than the number of bits in *n */
	if (index >= (sizeof(*n) * 8))
	return (-1);

/* create mask with 1 at the index, then OR with *n to set the bit */
	*n |= (1UL << index);

	return (1);
}
