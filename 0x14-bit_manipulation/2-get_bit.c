#include "main.h"
/**
 * get_bit - returns bit value at given index
 * @n: number int
 * @index: bit position in 0-index
 * Return: bit value or -1 if failed
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bits = 1;

	while (index--)
		bits <<= 1;

	if ((bits & n) == 0)
		return (0);
	else
		return (1);
}
