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
char **split_line(char *line);
int count_arguments(char *line);
void execute_command(char *line, char **env, char *prog_name, int line_number);
char *get_path(char **env);
char *find_path(char *cmd, char **env);
void free_argv(char **argv);

#endif /* SHELL_H */
