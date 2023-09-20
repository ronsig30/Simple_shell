#include "main.h"

/**
 * split_line - Split a string into multiple substrings (tokens).
 * @line: The string to be split.
 *
 * Return: A pointer to an array of strings (tokens).
 */
char **split_line(char *line)
{
	int bufsize = 50;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Error: Memory allocation failed in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);

	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}

		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				fprintf(stderr, "Error: Memory reallocation failed: tokens\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIM);
	}

	tokens[i] = NULL;
	return (tokens);
}
