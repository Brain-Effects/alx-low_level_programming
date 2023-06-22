#include "stdlib.h"
#include "main.h"

/**
 * _isupper - checks for uppercase character
 *
 * Retuern: 1 if c is uppercase, otherwise 0
 */
int _isupper(void)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
