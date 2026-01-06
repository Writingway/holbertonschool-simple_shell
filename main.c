#include "main.h"

/**
 * display_prompt - Prints the shell prompt
 * Description: Displays a prompt if the input is from a terminal
 * Return: void
 */
void display_prompt(void)
{
	printf("$ ");
	/* apply flush to ensure prompt is displayed immediately */
	fflush(stdout);
}

/**
 * read_input - Lire une ligne depuis l'entrée standard
 *
 * Return: La ligne lue
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 * Description: A simple C program that returns 0
*/
int main(int argc, char **argv, char **envp)
{
	char *line;
	char **tokens;
	int status = 0;
	int interactive = isatty(STDIN_FILENO);
	int line_number = 0;
	int builtin_result;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive)
			display_prompt();
		line = read_input();
		if (!line)
			break;
		tokens = split_line(line);
		free(line);
		if (!tokens || !tokens[0])
		{
			free_argv(tokens);
			continue;
		}
		builtin_result = handle_builtins(tokens, envp);
		if (builtin_result == -1)
		{
			free_argv(tokens);
			exit(status);
		}
		if (builtin_result == 1)
		{
			free_argv(tokens);
			continue;
		}
		status = execute_command(tokens, envp, argv[0], ++line_number);
		free_argv(tokens);
	}
	return (0);
}

