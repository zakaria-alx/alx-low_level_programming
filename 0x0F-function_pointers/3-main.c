#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - program that performs simple operations.
 * @argc: number of arguments passed to the function.
 * @argv: array of pointers to arguments.
 *
 * Return: if the number of arguments is wrong, print Error,
 * followed by a new line, and exit with the status 98,
 * if the operator is none of the above, print Error,
 * followed by a new line, and exit with the status 99,
 * if the user tries to divide (/ or %) by 0, print Error,
 * followed by a new line, and exit with the status 100.
 */
int main(int argc, char *argv[])
{
	int (*oprt)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	oprt = get_op_func(argv[2]);

	if (!oprt)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", oprt(atoi(argv[1]), atoi(argv[3])));
	return (EXIT_SUCCESS);
}
