#include "main.h"

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 * @prog_name: The name of the program
 * @line_number: The line number of the command
 * Return: int status of the executed command
 */
int execute_command(char *line, char **env, char *prog_name, int line_number)
{
	char **argv, *cmd_path;
	pid_t pid;
	int status;

	argv = split_line(line);
	if (argv == NULL || argv[0] == NULL)
	{
		free_argv(argv);
		return (0);
	}
	cmd_path = find_path(argv[0], env);
	if (cmd_path == NULL)
	{
		free_argv(argv);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_argv(argv);
		free(cmd_path);
		return (1);
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
	else
		waitpid(pid, &status, 0);
	free_argv(argv);
	free(cmd_path);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
