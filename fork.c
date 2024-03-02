#include "shell.h"

/*
 * custom_fork - Custom implementation of fork system call
 *
 * Return: On success, returns the process ID of the CP to the PP,
 *         returns 0 child process, and -1 on failure.
 */
pid_t custom_fork(void)
{
	pid_t child_pid;
	child_pid = fork(); /* Call the actual fork system call */

	if (child_pid == -1)
	{
		perror("custom_fork");
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}
