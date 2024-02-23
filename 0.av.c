#include <unistd.h>
#include <stdio.h>


/**
 * main -  Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 on (Success)
 */
int main(int argc, char *argv[])
{
	if (argv[1] == NULL)
	{
		printf("No command-line arguments provided.\n");
		return (0);
	}


	char **arg = argv + 1;
	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}
	return (0);
}
