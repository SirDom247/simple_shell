#include "main.h"
/**
 * builtins - Check if a command is a shell builtin
 * @argv: A double pointer to the parsed command
 *
 * Return: 1 if a builtin, 0 if not
 */
int builtins(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
		return (1);
	else if (strcmp(argv[0], "env") == 0)
		return (1);
	return (0);
}
