#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define DELIM " \t\r\n\a\""
extern char **environ;

void interactive_shell(void);
void shell_no_interactive(void);

char *read_line(void);
char **split_line(char *line);

int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);

int execute_cd(char **args);
int execute_exit();
int execute_env();
int execute_help();

#endif
