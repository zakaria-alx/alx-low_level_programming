#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int i, length = strlen(b);
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (i = length - 1; i >= 0; i--)
	{

		if ((b[i] != '0') && (b[i] != '1'))
		{
			return (0);
		}

		if (b[i] == '1')
		{
			result |= (1 << (length - i - 1));
		}
	}
	return result;
}
