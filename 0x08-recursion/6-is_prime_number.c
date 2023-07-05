#include <stdio.h>

/**
 * is_prime_number_helper - helper function to check if n is prime
 * @n: the number to check
 * @i: the current divisor to test
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number_helper(int n, int i)
{
	if (n <= 1)
	{
	return (0);
	}
	if (i * i > n)
	{
	return (1);
	}
	if (n % i == 0)
	{
	return (0);
	}
	return (is_prime_number_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number, 0 if not
 * @n: the number to check
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	return (is_prime_number_helper(n, 2));
}
