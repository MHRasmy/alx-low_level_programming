#include <stdio.h>
#include "lists.h"

/**
 * listint_len - print total no. nodes
 * @h: Pointer to listint_t
 *
 * Return: the total no. nodes
 */
size_t listint_len(const listint_t *h)
{
	int nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}
