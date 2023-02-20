#include "main.h"
/**
 * execute_line - Executes a line of input from the user
 * @argv: A double pointer to the tokens generated from the input line
 * @envp: A double pointer to the environment variables
 *
 * Return: 1 if the shell should continue running, 0 otherwise
 */
int execute_line(char **argv, char **envp)
{
	int status;

	if (argv[0] == NULL)
		return (1);

	if (builtins(argv))
		return (1);

	status = execute(argv, envp);
	return (status);
}

/**
 * execute - Executes a command with arguments.
 * @argv: Array of arguments passed to shell.
 * @envp: Array of environment variables.
 *
 * Return: Always returns 0.
 */
int execute(char **argv, char **envp)
{
	pid_t pid;
	int status;
	char *value = NULL;

	pid = fork();

	if (pid == 0)
	{
		value = _which(argv[0]);

		if (value == NULL)
		{
			printf("%s: command not found\n", argv[0]);
			exit(99);
		}

		if (execve(value, argv, envp) == -1)
		{
			perror("Error");
		}
		free(value);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
