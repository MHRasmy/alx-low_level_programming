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

	while (c < 16)
	{
		if (c < 10)
			putchar('0' + c);
		else
			putchar('a' + c - 10);
		c++;
	}
	putchar('\n');
	return (0);
}
