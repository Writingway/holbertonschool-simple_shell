#include "main.h"

/**
 * parse_input - Parse the input line to remove extra spaces and newlines
 * @line: The input line to parse
 * Return: void
 */
void parse_input(char *line)
{
	int i = 0, j = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			line[j++] = line[i];
		i++;
	}
	line[j] = '\0';
}
