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
	char **tokens;
	char *token;
	int count = 0, i = 0;
	char *line_copy;

	if (!line)
		return (NULL);
	/* On fait une copie de la ligne pour ne pas perdre le texte original */
	line_copy = strdup(line);
	if (!line_copy)
		return (NULL);
	/* compter le nombre de tokens */
	token = strtok(line_copy, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(line_copy);
	if (count == 0)
		return (NULL);
	/* allocation du tableau de tokens */
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free_argv(tokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
