#include "shell.h"
size_t _strlen(const char *str);
/**
 * _strdup - duplicating string
 * @str: string to be duplicated
 * Return: string
 */
char *_strdup(const char *str)
{
	size_t length = _strlen(str) + 1;
	char *new_str = (char *)malloc(length);
	size_t i = 0;

	if (new_str == NULL)
		return (NULL);

	for (; i < length; i++)
		new_str[i] = str[i];

	return (new_str);
}
