#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
 * if the number is greater than 0: is positive
 * if the number is 0: is zero
 * if the number is less than 0: is negative
 */

int main(0)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("%d ", n);
	if (n >= 0)
	{
		printf("is positive\n");
	} else if (n == 0)
	{
		printf("is zero\n");
	} else
{
		printf("is negative\n");
	}
	return (0);
}
