#include "shell.h"

/**
 * custom_xstat - Get file information.
 * @version: The version of the file structure.
 * @path: The path to the file.
 * @buf: The struct stat buffer to store file information.
 *
 * Return: 0 on success, -1 on failure.
 */
int custom_xstat(int version, const char *path, struct stat *buf)
{
	if (version != _STAT_VER)
	{
		errno = EINVAL; /* Invalid argument */
		return (-1);
	}
	if (stat(path, buf) == -1)
	{
		return (-1);
	}
	return (0);
}
