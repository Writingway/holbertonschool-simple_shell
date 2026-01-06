#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

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

/* main.c */
void display_prompt(void);
char *read_input(void);

/* split_line.c */
void free_argv(char **argv);
char **split_line(char *line);

/* execute.c */
int execute_command(char **argv, char **env, char *prog_name, int line_number);
int handle_builtins(char **tokens, char **env);

/* find_path.c */
char *find_path(char *cmd, char **env);

#endif /* SIMPLE_SHELL_H */
