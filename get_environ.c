#include "shell.h"
/**
 * _getenv - the get env function get the value of environment
 * @name: the name of the enviorment variable
 * Return: A pointer will be return
 */
char *_getenv(const char *name)
{
	int k, len;
	char **env;
	char *value;
	extern char **environ;


	if (!name)
		return (NULL);
	env = environ;
	for (k = 0; env[k]; k++)
	{
		for (len = 0; env[k][len] != '='; len++)
			;
		if (strncmp(name, env[k], len) == 0)
		{
			value = &env[k][len + 1];
			return (value);
		}
	}
	return (NULL);
}
