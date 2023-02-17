#include <stdio.h>

/**
 * main - prints and that piece of art is useful"
 * - Dora Korpar, 2015-10-19
 * Return: Always 0 (success)
 */

int main(void)
{
	char s[] = "and that piece of art is useful - Dora Korpar, 2015-10-19";

	int n = sizeof(s) / sizeof(s[0]);

	for (int i = 0; i < n; i++)
	{
		putchar(s[i]);
	}
	return (0);
}
