#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_len 1024
#define MAX_INPUT_LEN 256

char exe_command(char *command_with_args);
void execute_child_process(char *command, char *args[]);
char *_getenv(const char *name);
char *get_path(char *command);
void display_prompt(void);


#endif
