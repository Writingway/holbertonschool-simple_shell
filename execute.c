#include "main.h"

/**
 * buildtin_env - print the current env
 * @argv: arguments command
 * @env: environment variables
 * Return: 1 if succes
 */
int buildtin_env(char **argv, char **env)
{
	int i = 0;

	if (!argv || argv[0])
		return (0);

	if (strcmp(argv[0], "env") != 0)
		return (0); /*pas d'env */

	while (env && env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}

	free_argv(argv);
	return (1); /* execute env */
}

/**
 * buildtin_exit - exit shell if user types "exit"
 * @argv: arguments vector
 * @line: input line
 * @last_status: status of last executed command
 * Return: void
 */
void buildtin_exit(char **argv, char *line, int last_status)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free_argv(argv);
		free(line);
		exit(last_status);
	}
}

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 * @prog_name: The name of the program
 * @line_number: The line number of the command
 * @last_status: The status of the last executed command
 * Return: int status of the executed command
 */
int execute_command(char *line, char **env, char *prog_name,
	int line_number, int last_status)
{
	char **argv = split_line(line);
	char *cmd_path;
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (free_argv(argv), 0);
	/* buildtin exit avant de fork */
	buildtin_exit(argv, line, last_status);
	buildtin_env(argv, env);

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
