#include "main.h"

/**
 * buildtin_exit - exit shell if user types "exit"
 * @argv: arguments vector
 * @line: input line
 * Return: void
 */
void buildtin_exit(char **argv, char *line)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free_argv(argv);
		free(line);
		exit(0);
	}
}

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
	char **argv = split_line(line);
	char *cmd_path;
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (free_argv(argv), 0);
	/* buildtin exit avant de fork */
	buildtin_exit(argv, line);

	cmd_path = find_path(argv[0], env);
	if (!cmd_path)
		return (fprintf(stderr, "%s: %d: %s: not found\n", prog_name,
				line_number, argv[0]), free_argv(argv), 127);

	pid = fork();
	if (pid == -1)
		return (perror("fork"), free_argv(argv), free(cmd_path), 1);

	if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
			perror("execve"), free_argv(argv), free(cmd_path), exit(127);
	}
	else
		waitpid(pid, &status, 0);

	free_argv(argv);
	free(cmd_path);
	return (pid > 0 ? status >> 8 : 127);
}
