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
	char *cmd_path;

	argv = split_line(line);
	if (!argv || !argv[0])
	{
		free(argv);
		return;
	}

	if (access(argv[0], X_OK) == -1)
	{
		perror(argv[0]);
		free(argv);
		return;
	}

	cmd_path = find_command(argv[0], env);
	if (!cmd_path)
	{
		write(2,"Command not found\n", 18);
		free(argv);
		return; /* pas de fork */
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
	}
	else
	{
		waitpid(pid, &status, 0);
		free(argv);
		free(cmd_path);
	}

}
