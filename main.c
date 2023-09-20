#include "main.h"

/**
 * main - checks if shell is called
 *
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_shell();
	}
	else
	{
		shell_no_interactive();
	}
	return (0);
}
