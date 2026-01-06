#include "main.h"

/**
 * handle_builtins - Handle built-in commands
 * @argv: The argument vector
 * @env: The environment variables
 * Return: int status of the built-in command, -1 if not a built-in
 */
int handle_builtins(char **argv, char **env)
{
	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		return (-1); /* signal to exit */
	}

	if (strcmp(argv[0], "env") == 0)
	{
		int i = 0;

		while (env[i])
			printf("%s\n", env[i++]);
		return (1);
	}

	return (0); /* pas un builtin */
}

/**
 * execute_command - Executes a command
 * @argv: The command line to execute
 * @env: The environment variables
 * @prog_name: Name of the program
 * @line_number: Current line number for error reporting
 * Return: int status of the executed command
 */
int execute_command(char **argv, char **env, char *prog_name, int line_number)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (!argv || !argv[0])
		return (0);

	if (strchr(argv[0], '/')) /* chemin absolu ou relatif */
		cmd_path = argv[0];
	else /* chercher dans PATH */
	{
		cmd_path = find_path(argv[0], env);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", prog_name, line_number, argv[0]);
			return (127);
		}
	}
	pid = fork();
	if (pid == 0) /* child */
		execve(cmd_path, argv, env), perror("execve"), exit(127);
	else if (pid < 0)
		return (perror("fork"), 1);
	waitpid(pid, &status, 0);

	status = status >> 8;

	if (!strchr(argv[0], '/')) /* free seulement si find_path a malloc */
		free(cmd_path);
	return (status);
}
