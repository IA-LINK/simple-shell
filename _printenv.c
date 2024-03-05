#include "shell.h"
/**
 * print_env - print the environment variables
 *
 * the function print the env
 */
void print_env(void)
{
	int k;
	char **env = environ;

	for (k = 0; env[k]; k++)
	{
		write(STDOUT_FILENO, env[k], strlen(env[k]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
