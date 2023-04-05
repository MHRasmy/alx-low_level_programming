#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t list, set head to NULL
 * @head: Pointer to pointer listint_t
 *
 * Return: address of the new element, NULL if failed
 */
void free_listint2(listint_t **head)
{
	listint_t *curr;

	if ((*head) == NULL)
		return;

	while ((*head) != NULL)
	{
		curr = (*head);
		(*head) = (*head)->next;
		free(curr);
	}

	(*head) = NULL;
}
