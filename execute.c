#include "main.h"

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 * @prog_name: The name of the program
 * @line_number: The line number of the command
 * Return: void
 */
void execute_command(char *line, char **env, char *prog_name, int line_number)
{
	char **argv, *cmd_path;
	pid_t pid;
	int status;

	argv = split_line(line);
	if (argv == NULL || argv[0] == NULL)
	{
		free_argv(argv);
		return;
	}
	cmd_path = find_path(argv[0], env);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prog_name, line_number, argv[0]);
		free_argv(argv);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_argv(argv);
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
		{
			perror("execve");
			free_argv(argv);
			free(cmd_path);
			exit(127);
		}
	}
	if (pid > 0)
		waitpid(pid, &status, 0);
	free_argv(argv);
	free(cmd_path);
}
