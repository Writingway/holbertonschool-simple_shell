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
	ssize_t read;

	/*Cette fonction lit une ligne complète */
	read = getline(&line, &len, stdin);
	if (read == -1) /* Si erreur de lecture */
	{
		free(line);
		exit(0); /* on quitte proprement */
	}
	return (line);
}
