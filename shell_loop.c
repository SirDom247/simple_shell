#include "main.h"

/**
 * shell_loop - Contains the primary loop for the shell program
 * @envp: A double pointer to the environment variables
 */
void shell_loop(char **envp)
{
	char *line = NULL;
	size_t len = 0;
	int status;
	ssize_t nread;

	do {
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			perror("Error reading input");
		else if (*line != '\n')
			status = process_line(line, envp);
	} while (status);

	free(line);
}
