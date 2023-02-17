#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/**
 * main - random number to the variable n
 * compare n to zero and return n
 * Return: Always 0 (Success)
 */
int main(void)
{
	int c = 0;

	for (c = 0; c < 10; c++)
		putchar(c % 10 + '0');
	putchar('\n');
	return (0);
}
