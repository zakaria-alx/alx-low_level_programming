#include "main.h"

/**
 * _getlen - a function that return length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */
size_t _getlen(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename:  is the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
		len = write(fd, text_content, _getlen(text_content));
	close(fd);
	if (len == -1)
		return (-1);
	return (1);
}
