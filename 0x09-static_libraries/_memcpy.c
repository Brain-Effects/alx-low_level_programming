#include "main.h"
#include <stdio.h>

/**
 * _memcpy() - Copies n bytes from memory area src to memory area dest
 * @n: The number of bytes to be coppied
 *
 * Return: Nothing.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	dest[i] = src[i];

	return dest;
}
