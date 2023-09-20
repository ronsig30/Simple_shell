#include "main.h"

/**
 * new_process - Create and execute a new child process.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in new_process: execvp failed");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("Error in new_process: fork failed");
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
