#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - applies a function to each element of an array
 *
 * @array: array of integers
 * @size: size of the array
 * @action: pointer to a function that takes an integer argument
 * and returns void
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
