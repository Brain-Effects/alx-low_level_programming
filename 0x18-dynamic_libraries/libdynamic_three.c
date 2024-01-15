#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * _strcat - concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	return (strcat(dest, src));
}

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes to use from src
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	return (strncat(dest, src, n));
}

/**
 * _strncpy - copies a string, including the terminating null byte (\0),
 *            to the buffer pointed to by dest, up to n bytes
 * @dest: The destination to copy to
 * @src: The source to copy from
 * @n: The maximum number of bytes to use from src
 *
 * Return: the pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	return (strncpy(dest, src, n));
}

/**
 * _strcmp - compares two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}

/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 *           with the constant byte b
 * @s: The memory area to fill
 * @b: The constant byte
 * @n: The number of bytes to fill
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	return (memset(s, b, n));
}
