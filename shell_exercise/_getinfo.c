#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->argc = 0;
	info->argc = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->argc)
	{
		info->argc = strtok(info->argc, " \t");
		if (!info->argc)
		{

			info->argc = malloc(sizeof(char *) * 2);
			if (info->argc)
			{
				info->argc[0] = strdup(info->argc);
				info->argc[1] = NULL;
			}
		}
		for (i = 0; info->argc && info->argc[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argc);
	info->argc = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->argc);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		free((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		putchar(BUF_FLUSH);
	}
}
