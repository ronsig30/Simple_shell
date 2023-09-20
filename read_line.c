#include "main.h"

/**
 * read_line - Read a line from stdin.
 *
 * Return: A pointer to a string containing the line content.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("read_line error");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
