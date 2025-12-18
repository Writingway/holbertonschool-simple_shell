#include "main.h"

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	printf("$ "); /* titre de la fenêtre */
	fflush(stdout); /* s'assurer que ça s'affiche immédiatement */
}

/**
 * read_line - Reads a line of input from stdin
 * Return: The line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/*Cette fonction lit une ligne complète */
	read = getline(&line, &len, stdin);
	if (read == -1) /* Si erreur de lecture */
	{
		free(line);
		printf("\n");
		exit(EXIT_SUCCESS); /* on quitte proprement */
	}
	return (line);
}

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 */
void execute_command(char *line, char **env)
{
	char *argv[2];
	pid_t pid;

	line[strcspn(line, "\n")] = 0;
	if (line[0] == '\0')
		return;

	argv[0] = line;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return;
	}

	if (pid == 0) /* fils */
	{
		if (execve(argv[0], argv, env) == -1)
		{
			fprintf(stderr, "shell: %s: command not found\n", argv[0]);
			/*printf("argv[0] %s argv %s env %s\n", argv[0], *argv, *env);*/
		}
		exit(EXIT_FAILURE);
	}
	else /* père*/
	{
		int status;

		waitpid(pid, &status, 0);
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
	char *line;
	char buf[1024];

	while (1)
	{
		print_prompt();
		line = read_line();
		execute_command(line, envp);
		free(line);
	}
	return (0);
}
