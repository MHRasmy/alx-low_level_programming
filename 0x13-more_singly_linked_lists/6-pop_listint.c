#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - frees a listint_t list, return head data
 * @head: Pointer to pointer listint_t
 *
 * Return: head data, 0 if empty
 */
int pop_listint(listint_t **head)
{
	int n = 0;
	listint_t *curr;

	if ((*head) == NULL)
	{
		return (n);
	}
	else
	{
		curr = (*head);
		(*head) = (*head)->next;
		n = curr->n;

		free(curr);
	}

	return (n);
}
