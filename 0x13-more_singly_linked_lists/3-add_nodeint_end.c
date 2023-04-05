#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds node at the end of a list
 * @head: Pointer to pointer listint_t
 * @n: integer n
 *
 * Return: address of the new element, NULL if failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}

	return (new_node);
}
