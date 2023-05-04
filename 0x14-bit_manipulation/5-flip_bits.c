#include "main.h"
/**
 * flip_bits - a function that returns the number of bits you would need
 * to flip to get from one number to another.
 * @n: the first number
 * @m: the second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int res = 1;
	unsigned long int diff = n ^ m;

	unsigned int i, j = 0;

	for (i = 0; i < (sizeof(8UL) * 8); i++)
	{
		if (res == (diff & res))
			j++;
		res <<= 1;
	}

	return (j);
}
