#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

void display_prompt(void);
char *read_input(void);
char **split_line(char *line);
int count_arguments(char *line);
void execute_command(char *line, char **env);

char *_getenv(const char *name);

#endif /* SHELL_H */
