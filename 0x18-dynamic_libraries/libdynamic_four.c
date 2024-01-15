#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: The destination to copy to
 * @src: The source to copy from
 * @n: The number of bytes to copy
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	return (memcpy(dest, src, n));
}

/**
 * _strchr - locates first occurrence of c (converted to a char) in string s
 * @s: The string to search
 * @c: The character to search for
 *
 * Return: a pointer to the located character, or NULL if the
 * character does not appear in the string
 */
char *_strchr(char *s, char c)
{
	return (strchr(s, c));
}

/**
 * _strspn - calculates the length of the initial segment of s which consists
 *           entirely of bytes in accept
 * @s: The string to search
 * @accept: The bytes to search for
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	return (strspn(s, accept));
}

/**
 * _strpbrk - locates the first occurrence in the string s of any of
 *             the bytes in the string accept
 * @s: The string to search
 * @accept: The bytes to search for
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	return (strpbrk(s, accept));
}

/**
 * _strstr - finds first occurrence of substring needle in string haystack
 * @haystack: The string to search
 * @needle: The substring to search for
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	return (strstr(haystack, needle));
}
