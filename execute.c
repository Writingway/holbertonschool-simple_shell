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

	/*Split the line with split_line function */
	argv = split_line(line);
	/*Check if argv is NULL or the first argument is NULL */
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}
	/*Check if the command exists using access function*/
	if ((access(argv[0], F_OK)) == -1)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		free(argv);
		return;
	}
	pid = fork();
	printf("Forked process with PID: %d & %d\n", pid, getpid());
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
