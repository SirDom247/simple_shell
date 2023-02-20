#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

char *_which(char *argv);
int display(char **envp);
int process_line(char *line, char **envp);
int execute_line(char **argv, char **envp);
void shell_loop(char **envp);
int builtins(char **argv);
int execute(char **argv, char **envp);
char **tokenize_line(char *line);

#endif /* MAIN_H */
