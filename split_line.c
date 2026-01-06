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
	char **tokens = NULL;
	char *token;
	int count = 0;

	token = strtok(line, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}

	if (count == 0)
		return (NULL);

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

