#include "shell.h"

/*
 * custom_getline - Custom implementation of getline function
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the variable containing the size of the buffer
 * @stream: File stream to read from (stdin in this case)
 *
 * Return: The number of characters read, or -1 if an error occurs.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[MAX_BUFFER];
	static size_t buf_pos;
	static ssize_t bytes_read;
	ssize_t total_read = 0;
	int found_newline = 0;
	if (buf_pos >= (size_t)bytes_read || bytes_read == 0)
	{
		bytes_read = read(fileno(stream), buffer, MAX_BUFFER);
		if (bytes_read <= 0)
		{
			return (-1);
		}
		buf_pos = 0;
	}
	while (buf_pos < (size_t)bytes_read)
	{
		if (buffer[buf_pos] == '\n')
		{
			found_newline = 1;
			break;
		}
		buf_pos++;
		total_read++;
	}
	if (total_read > 0)
	{
		if (*lineptr == NULL || *n < (size_t)(total_read + 1))
		{
			*n = total_read + 1;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		strncpy(*lineptr, buffer + (buf_pos - total_read), total_read);
		(*lineptr)[total_read] = '\0';
	}
	else
	{
		*lineptr = NULL;
	}
	if (found_newline)
	{
		buf_pos++;
	}
	return (total_read);
}
