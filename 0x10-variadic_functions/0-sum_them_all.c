#include "variadic_functions.h"

/**
 * sum_them_all - a function that returns the sum of all its parameters.
 * @n: unsigned int.
 * Return: sum of parameters or 0 if n == 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	int t = 0;

	if (n == 0)
	{
		return (0);
	};

	va_start(numbers, n);
	for (i = 0; i < n; i++)
	{
		t += va_arg(numbers, int);
	};
	va_end(numbers);

	return (t);
}
