#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads a text file and prints
 * it to the POSIX standard output.
 * @filename: A pointer to the name of the file.
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 * 0 if:
 * filename is NULL
 * file can not be opened
 * write fails or does not write the expected amount of bytes
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t opn, rd, wrt;
	char *store;

	if (filename == NULL)
		return (0);

	store = malloc(sizeof(char) * letters);
	if (store == NULL)
		return (0);

	opn = open(filename, O_RDONLY);
	rd = read(opn, store, letters);
	wrt = write(STDOUT_FILENO, store, rd);

	if (opn == -1 || rd == -1 || wrt == -1 || wrt != rd)
	{
		free(store);
		return (0);
	}

	free(store);
	close(opn);

	return (wrt);
}
