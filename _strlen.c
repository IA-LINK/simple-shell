#include "shell.h"
/**
 * _strlen - length of string
 * @str: string
 * Return: number of characters
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
