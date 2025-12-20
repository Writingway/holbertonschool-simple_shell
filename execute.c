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

	/*Split the line with split_line function */
	argv = split_line(line);
	/*Check if argv is NULL or the first argument is NULL */
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}
<<<<<<< HEAD
	cmd_path = find_path(argv[0], env);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		free(argv);
		return;
=======
	cmd_path = find_command(argv[0], env);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		free(argv);
		return; /* pas de fork */
>>>>>>> 7c246778a6d2622781c67dfb6b87e67f5b7dff48
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
