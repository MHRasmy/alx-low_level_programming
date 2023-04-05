#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - frees a listint_t list, return head data
 * @head: Pointer to pointer listint_t
 *
 * Return: head data, 0 if empty
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *curr = head;

	for (i = 0; i < index; i++)
	{
		if (!(curr)->next)
			return (NULL);
		curr = curr->next;
	}

	return (curr);
}
