#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/**
 * check97 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check98 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @fd_src: file descriptor of file_from, or -1
 * @fd_dest: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check98(ssize_t check, char *file, int fd_src, int fd_dest)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_src != -1)
			close(fd_src);
		if (fd_dest != -1)
			close(fd_dest);
		exit(98);
	}
}

/**
 * check99 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @fd_src: file descriptor of file_from, or -1
 * @fd_dest: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check99(ssize_t check, char *file, int fd_src, int fd_dest)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_src != -1)
			close(fd_src);
		if (fd_dest != -1)
			close(fd_dest);
		exit(99);
	}
}

/**
 * check100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check100(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - a program that copies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_src, fd_dest, close_dest, close_src;
	ssize_t len_read, len_write;
	char buffer[BUFF_SIZE];
	mode_t file_perm;

	check97(argc);
	fd_src = open(argv[1], O_RDONLY);
	check98((ssize_t)fd_src, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check99((ssize_t)fd_dest, argv[2], fd_src, -1);
	len_read = BUFF_SIZE;
	while (len_read == BUFF_SIZE)
	{
		len_read = read(fd_src, buffer, BUFF_SIZE);
		check98(len_read, argv[1], fd_src, fd_dest);
		len_write = write(fd_dest, buffer, len_read);
		if (len_write != len_read)
			len_write = -1;
		check99(len_write, argv[2], fd_src, fd_dest);
	}
	close_dest = close(fd_dest);
	close_src = close(fd_src);
	check100(close_dest, fd_dest);
	check100(close_src, fd_src);
	return (0);
}
