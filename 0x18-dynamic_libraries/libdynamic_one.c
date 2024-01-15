#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (putchar(c));
}

/**
 * _islower - checks for lowercase character
 * @c: The character to check
 *
 * Return: 1 if c is lowercase, 0 otherwise
 */
int _islower(int c)
{
	return (islower(c));
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 *
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	return (isalpha(c));
}

/**
 * _abs - computes the absolute value of an integer
 * @n: The integer to compute
 *
 * Return: The absolute value of the integer
 */
int _abs(int n)
{
	return (abs(n));
}

/**
 * _isupper - checks for uppercase character
 * @c: The character to check
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	return (isupper(c));
}
