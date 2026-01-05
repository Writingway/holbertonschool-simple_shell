#include "main.h"

/**
 * display_prompt - Prints the shell prompt
 * Description: Displays a prompt if the input is from a terminal
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		/* titre de la fenêtre */
		printf("$ ");
		/* s'assurer que ça s'affiche immédiatement */
		fflush(stdout);
	}
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
	char *input;
	char *prog_name = argv[0];
	int line_number = 0;
	int status = 0;
	int interactive = isatty(STDIN_FILENO);

	(void)argc;

	while (1)
	{
		display_prompt();
		input = read_input();
		status = execute_command(input, envp, prog_name, ++line_number,
			status, interactive);
		free(input);
	}
	return (0);
}
