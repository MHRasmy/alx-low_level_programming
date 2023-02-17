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

	while (c < 10)
	{
		putchar('0' + c);
		if (c != 9)
		{
			putchar(',');
			putchar(' ');
		}
		c++;
	}
	putchar('\n');
	return (0);
}
