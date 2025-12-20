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

	if (access(argv[0], X_OK) == -1) /* Est-ce que argv[0] est une commande exécutable ? */
	{
		perror(argv[0]); /* message d'erreur */
		free(argv);
		return; /* retour au prompt */
	}

	cmd_path = find_command(argv[0], env);

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
			free(argv);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(argv);
	}

}
