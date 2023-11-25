#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to change
 * @index: index at which to set bit
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
/* check if index is greater than the number of bits in *n */
	if (index >= (sizeof(*n) * 8))
	return (-1);

/* create mask with 0 at the index and 1's elsewhere,*/
/* then AND with *n to clear the bit */
	*n &= ~(1UL << index);

	return (1);
}
