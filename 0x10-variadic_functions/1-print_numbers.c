#include "variadic_functions.h"

/**
 * print_numbers - a function that prints numbers, followed by a new line.
 * @separator:  is the string to be printed between numbers.
 * @n: is the number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	va_start(numbers, n);
	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
		{
			printf("%d", va_arg(numbers, int));
		}
		else
		{
			printf("%d", va_arg(numbers, int));
			if (i < n - 1 && separator != NULL)
			{
				printf("%s", separator);
			}
		}
	}
	va_end(numbers);
	printf("\n");
}
