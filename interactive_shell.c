#include "main.h"

/**
 * interactive_shell - Implements a basic UNIX-like command line interpreter.
 *
 * This function continuously prompts the user for input, reads their command,
 * and executes it until a specific exit condition is met.
 *
 * Return: This function does not return a value.
 */
void interactive_shell(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("shell_prompt>$ ");
		line = read_line();
		args = split_line(line);
		status = execute_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
