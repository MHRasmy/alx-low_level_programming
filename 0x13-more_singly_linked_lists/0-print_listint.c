#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a list
 * @h: Pointer to listint_t
 *
 * Return: the total no. nodes
 */
size_t print_listint(const listint_t *h)
{
	int nodes = 0;

	if (!h)
		return (0);
	while (h)
	{
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	}
	return (nodes);
}
