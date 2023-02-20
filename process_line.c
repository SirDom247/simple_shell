#include "main.h"
/**
 * process_line - Processes a single line of input from the user
 * @line: The line to process
 * @envp: A double pointer to the environment variables
 *
 * Return: 1 if the shell should continue running, 0 otherwise
 */
int process_line(char *line, char **envp)
{
	int status;
	char **argv;

	argv = tokenize_line(line);

	if (!argv)
		return (1);

	status = execute_line(argv, envp);

	free(argv);
	return (status);
}

/**
 * tokenize_line - Tokenizes a single line of input from the user
 * @line: The line to tokenize
 *
 * Return: A double pointer to the tokens generated from the input line
 */
char **tokenize_line(char *line)
{
	int bufsize = TOK_BUFSIZE, pos = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Error reallocating memory for tokens");
				return (NULL);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}
