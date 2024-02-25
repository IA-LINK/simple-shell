#include "shell.h"

void sigint_handler(int sig);
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
int builtin_exit(void);
int builtin_help(void);

/**
 * sigint_handler - Handles the SIGINT signal (Ctrl+C).
 * @sig: The signal number.
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * read_line - Reads a line of input from the user.
 * Return: The line of input read.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	if (getline(&line, &bufsize, stdin) == -1)
	{
		perror("read_line");
		exit(EXIT_FAILURE);
	}
	return (line);
}

/**
 * split_line - Splits a line of input into individual tokens/arguments.
 * @line: The line of input to be split.
 * Return: An array of tokens.
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	if (!tokens)
	{
		perror("split_line");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("split_line");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute_command - Executes a command.
 * @args: An array of strings representing the command and its arguments.
 * Return: 1 on success, 0 otherwise.
 */
int execute_command(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return (builtin_exit());
	}
	if (strcmp(args[0], "help") == 0)
	{
		return (builtin_help());
	}
	pid_t pid, wpid;
	int status;
	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * builtin_exit - Implements the built-in exit command.
 * Return: Always 0.
 */
int builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * builtin_help - Implements the built-in help command.
 * Return: Always 1.
 */
int builtin_help(void)
{
	printf("Simple Shell\n");
	printf("------------\n");
	printf("This is a simple shell implementation.\n");
	printf("Supported built-in commands:\n");
	printf("- exit: Exit the shell\n");
	printf("- help: Display this help message\n");
	return (1);
}

/**
 * main - Entry point of the shell program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *line;
	char **args;
	int status;
	signal(SIGINT, sigint_handler);
	do {
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);
		free(line);
		free(args);
	} while (status);
	return (EXIT_SUCCESS);
}
