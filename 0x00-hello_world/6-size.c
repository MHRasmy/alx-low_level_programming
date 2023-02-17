#include <stdio.h>

/**
 * main - prints the size of various types on
 * the computer it is compiled and run on.
 * Return: Always 0 (success)
 */

int main(void)
{
	printf("Size of a char: %ld bytes\n", sizeof(char));
	printf("Size of an int: %ld bytes\n", sizeof(int));
	printf("Size of a long int: %ld bytes\n", sizeof(long));
	printf("Size of a long long int: %ld bytes\n", sizeof(long long));
	printf("Size of a float: %ld bytes\n", sizeof(float));
	return (0);
}
