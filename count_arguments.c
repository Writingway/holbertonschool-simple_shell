#include "main.h"

/**
 * count_arguments - Counts the number of arguments in a command line
 * @line: The input command line
 * Return: The number of arguments
 */
int count_arguments(char *line)
{
	int count = 0;
	int in_word = 0;

	while (*line != '\0')
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
		line++;
	}

	return (count);
}
