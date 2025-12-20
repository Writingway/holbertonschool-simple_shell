#include "main.h"

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
	{
		free(argv);
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}

