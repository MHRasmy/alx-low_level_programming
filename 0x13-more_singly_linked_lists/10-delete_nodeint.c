#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at a given position
 * @head: pointer to the head of the list
 * @index: index of new node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *curr = *head;
	listint_t *temp;

	if (idx == 0)
	{
		temp = (*head)->next;
		free(*head);
		return (1);
	}

	for (i = 0; i <= idx; i++)
	{
		if (!curr)
		{
			break;
		}
		else if (i == idx - 1)
		{
			if (curr->next->next)
				temp = curr->next->next;
			else
				curr->next->next = NULL;
			free(curr->next);
			curr->next = temp;
			return (1);
		}
		curr = curr->next;
	}
	return (-1);
}