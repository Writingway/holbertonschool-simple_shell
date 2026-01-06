#include "main.h"

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
