#include "shell.h"
/**
 * _strcat -  this is a function that concatenate two strings
 * @dest: the char string to be concatenated
 * @src: chara string
 * Return: this return concated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
