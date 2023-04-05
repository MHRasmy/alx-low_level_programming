#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t
 * @head: pointer to the head of the list
 *
 * Return: sum, 0 if empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *curr = head;

	while (curr)
	{
		sum += curr->n;
		curr = curr->next;
	}

	return (sum);
}
