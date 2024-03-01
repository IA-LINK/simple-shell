#include "shell.h"

/**
 * custom_strtok - custom implementation of strtok function
 * @str: the string to tokenize
 * @delim: the delimiter characters
 *
 * Return: a pointer to the next token, or NULL if no more tokens are found
 */
char *custom_strtok(char *str, const char *delim)
{
	static char *last_pos;
	char *start;
	if (str != NULL)
	{
		last_pos = str;
	}
	else if (last_pos == NULL)
	{
		return (NULL);
	}
	while (*last_pos != '\0' && strchr(delim, *last_pos) != NULL)
	{
		last_pos++;
	}
	if (*last_pos == '\0')
	{
		return (NULL); /* If no more tokens left, return NULL */
	}
	start = last_pos;
	while (*last_pos != '\0' && strchr(delim, *last_pos) == NULL)
	{
		last_pos++;
	}
	if (*last_pos != '\0')
	{
		*last_pos = '\0';
		last_pos++;
	}
	return (start);
}
