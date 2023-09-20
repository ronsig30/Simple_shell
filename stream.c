#include "main.h"
/**
 * read_stream - Read a line from the input stream.
 *
 * Return: A pointer to the string containing the read line.
 */
char *read_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed in read_stream\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();

		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "Error: Memory reallocation failed in read_stream\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
