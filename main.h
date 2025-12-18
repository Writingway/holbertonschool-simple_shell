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

void display_prompt(void);
char *read_input(void);
void parse_input(char *line);
void execute_command(char *line, char **env);

#endif /* SHELL_H */
