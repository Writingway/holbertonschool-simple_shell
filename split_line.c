#include "main.h"


/**
 * free_argv - Free the memory allocated for argv
 * @argv: The argument vector to free
 * Return: void
*/
void free_argv(char **argv)
{
	int i = 0;

	if (argv == NULL)
		return;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}


/**
 * split_line - Parse the input line to remove extra spaces and newlines
 * @line: The input line to parse
 * Return: void
 */
char **split_line(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	/* Count the number of arguments */
	int argc = count_arguments(line);

	/* Allocate memory for argv with the exact number of arguments "argc"*/
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		if (strlen(token) > 0)
		{
			argv[i] = strdup(token);
			i++;
		}
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}

