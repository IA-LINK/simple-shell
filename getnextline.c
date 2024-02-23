#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point ofthe program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	printf("$ ");
	fflush(stdout);

	char command[100];

	fgets(command, sizeof(command), stdin);

	printf("%s", command);
	return (0);
}
