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
#include "main.h"

int main(int argc, char **argv, char **envp)
{
	char *input;
	char **g_env;

	(void)argc;
	(void)argv;

	g_env = envp;

	while (1)
	{
		display_prompt();
		input = read_input();
		execute_command(input, g_env);
		free(input);
	}
	return (0);
}
