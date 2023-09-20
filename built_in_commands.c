#include "main.h"
/**
 * execute_cd - Change the current working directory.
 * @args: An array of arguments, where args[1] is the directory path.
 *
 * Return: Always returns 1.
 */
int execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		const char *message = "cd: missing argument\n";

		write(STDERR_FILENO, message, strlen(message));
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	return (1);
}
/**
 * execute_env - Print the environment variables.
 * @args: An array of arguments (unused).
 *
 * Return: Always returns 1.
 */
int execute_env(char **args)
{
	char **env;

	(void)args;

	for (env = environ; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * execute_help - Display the help message for the shell.
 *
 * Return: Always returns 1.
 */
int execute_help(void)
{
	const char *help_message =
	    "Simple Shell Help:\n"
	    " - cd [directory]: Change the current working directory.\n"
	    " - env: Print environment variables.\n"
	    " - help: Display this help message.\n"
	    " - exit: Exit the shell.\n";

	write(STDOUT_FILENO, help_message, strlen(help_message));
	return (1);
}
/**
 * execute_exit - Exit the shell.
 *
 * Return: Always returns 0.
 */
int execute_exit(void)
{
	const char *exit_message = "Exiting the shell...\n";

	write(STDOUT_FILENO, exit_message, strlen(exit_message));
	return (0);
}
