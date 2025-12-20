#include "main.h"

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 */
void execute_command(char *line, char **env)
{
	char **argv, *cmd_path;
	pid_t pid;
	int status;

	argv = split_line(line);
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}
	cmd_path = find_path(argv[0], env);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		free(argv);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(argv);
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
		{
			perror("execve");
			free(argv);
			free(cmd_path);
			exit(127);
		}
		return;
	}
	waitpid(pid, &status, 0);
	free(argv);
	free(cmd_path);
}
