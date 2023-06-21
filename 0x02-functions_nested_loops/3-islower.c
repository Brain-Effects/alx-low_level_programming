#include "unistd.h"
#include "main.h"
/**
 * _islower - checkes for lowercase character
 * @c: the character to check
 *
 * Return: 1 if c is lowercase, othewise 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	return (1);
	else
	return (0);
}
