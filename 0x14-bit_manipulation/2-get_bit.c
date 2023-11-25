#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to check
 * @index: index at which to check bit
 * Return: value of the bit, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* check if index is greater than the number of bits in n */
	if (index >= (sizeof(n) * 8))
	return (-1);

/* shift bits to the right up to index, then AND with 1 to get the bit value */
	return ((n >> index) & 1);
}
