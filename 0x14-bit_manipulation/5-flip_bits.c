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
	if (index >= sizeof(8UL) * 8)
	{
		return (-1);
	}
	*n ^= (1UL << index);
	return (1);
}
