#include "main.h"

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 */
void execute_command(char *line, char **env)
{
	char **argv;
	pid_t pid;
	int status;

	argv = split_line(line);
	if (!argv || !argv[0])
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
