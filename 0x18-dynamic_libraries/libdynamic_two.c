#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: The number to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (isdigit(c));
}

/**
 * _strlen - returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	return (strlen(s));
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @s: The string to print
 */
void _puts(char *s)
{
	puts(s);
}

/**
 * _strcpy - copies the string pointed to by src, including the
 *           terminating null byte (\0), to the buffer pointed to by dest
 * @dest: The destination to copy to
 * @src: The source to copy from
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}

/**
 * _atoi - convert a string to an integer
 * @s: The string to convert
 *
 * Return: The integer value of the converted string
 */
int _atoi(char *s)
{
	return (atoi(s));
}
