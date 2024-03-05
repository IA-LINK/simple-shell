#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_LEN 1024
#define MAX_BUFFER 1024

extern char **environ;
char *_strncpy(char *dest, char *src, int n);
char *custom_strtok(char *str, const char *delim);
char *_strtrim(char *c);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name);
char *_strdup(const char *src);
char *get_path(char *command);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *str1, const char *str2);
int _strlen_const(const char *s);
int exe_command(char *command_with_args);
size_t _strlen(const char *str);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
pid_t custom_fork(void);
void display_prompt(void);
void print_env(void);
void execute_child_process(char *command, char *args[]);


#endif /* SHELL_H */
