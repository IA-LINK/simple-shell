#include "shell.h"
size_t _strlen(const char *str);
/**
 * signal_handler - handles signals for ctrl c
 * @signal: signal number
 * Return: nothing
 */
void signal_handler(int signal)
{
	char *prompt = "\n$ ";

	(void)signal;
	write(1, prompt, _strlen(prompt));
	fflush(stdout);
}
