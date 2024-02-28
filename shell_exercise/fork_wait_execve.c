#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - exercise: fork + wait + execve
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int j = 0;
	int status;
	char *argv[] = {"bin/ls", "-l", "tmp/", NULL};

	my_pid = getpid();
	while (j <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("error");
			return (1);
		}
		wait(&status);
		j++;
	}
	if (child_pid == 0)
	{
		printf("--------------------------------\n\n");
		printf("ID JAMES: %u\n\nID PAUL: %u\n\n", getpid(), getppid());
		printf("--------------------------------\n\n");

	}
	else
	{
		printf("%u Is PAUL AND ID JI: %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
/*perror("ERROR:");*/
	}
	return (0);
}
