#include "main.h"

/**
 * free_argv - Free the memory allocated for argv array
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
	char **tokens;
	char *token;
	int count = 0;
	char *line_copy;

	if (!line)
		return (NULL);
	/* We make a copy of the line to not lose the original text */
	line_copy = strdup(line);
	if (!line_copy)
		return (NULL);
	/* count the number of tokens */
	token = strtok(line_copy, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(line_copy);
	if (count == 0)
		return (NULL);
	/* allocation of the tokens array */
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	count = 0;
	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[count] = strdup(token);
		if (!tokens[count])
		{
			free_argv(tokens);
			return (NULL);
		}
		count++;
		token = strtok(NULL, " \t\n");
	}
	tokens[count] = NULL;
	return (tokens);
}
