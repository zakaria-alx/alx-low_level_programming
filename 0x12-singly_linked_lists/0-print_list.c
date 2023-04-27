#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - check the code for Holberton School students.
 * @head: name of the list
 * Return: the number of nodes.
 */
size_t print_list(const list_t *head)
{
	int count = 0;

	while (head)
	{
		if (head->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", head->len, head->str);
		}
		count++;
		head = head->next;
	}
	return (count);
}
