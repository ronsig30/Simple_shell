#include "main.h"

/**
 * execute_args - Execute a command, checking if it is a built-in or a process.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int execute_args(char **args)
{
	char *builtin_commands[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	int (*builtin_functions[])(char **) = {
		&execute_cd,
		&execute_env,
		&execute_help,
		&execute_exit
	};

	int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (; i < (int)(sizeof(builtin_commands) / sizeof(char *)); i++)
	{
		if (strcmp(args[0], builtin_commands[i]) == 0)
		{
			return ((*builtin_functions[i])(args));
		}
	}

	return (new_process(args));
}
