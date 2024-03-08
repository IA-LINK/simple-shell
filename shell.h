#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

/* global variables */

typedef struct {
	char **tokens; 
	int argc;
	char *cmd;
	int status;
	int lineno;
	int fileno;
	char *file;
	int readfd;
} info_t;
extern char **environ;
int is_cmd(info_t *info, char *path);
#endif
