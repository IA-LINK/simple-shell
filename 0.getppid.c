#include <stdio.h>
#include <unistd.h>

/*
 * main - Entry point of the program
 *
 * Author: James I and Paul L
 * Return: Always returns 0 to indicate success
 *
 * Description: A program to print the PID of the parent process.
 */
int main(void)
{
	printf("Parent PID: %d\n", getppid());
	return (0);
}

