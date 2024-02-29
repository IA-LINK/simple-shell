#include "shell.h"
/**
 * _strncpy - copies string
 * @dest: string 1 value
 * @src: string 2 value
 * @n: size
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k;

	for (k = 0; k < n && src[k] != '\0'; k++)
	{
		dest[k] = src[k];
	}

	for (; k < n; k++)
	{
		dest[k] = '\0';
	}

	return (dest);
}
