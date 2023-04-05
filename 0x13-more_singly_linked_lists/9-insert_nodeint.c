#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - insert node at a given position
 * @head: pointer to the head of the list
 * @idx: index of new node
 * @n: value of new node
 *
 * Return:address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new_node;
	listint_t *curr = *head;
	listint_t *temp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL || !head)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = (*head);
		(*head) = new_node;
		return (new_node);
	}

	for (i = 0; i <= idx; i++)
	{
		if (!curr)
		{
			break;
		}
		else if (i == idx - 1)
		{
			temp = curr->next;

			curr->next = new_node;
			new_node->next = temp;
			return (new_node);
		}
		curr = curr->next;
	}
	return (NULL);
}
