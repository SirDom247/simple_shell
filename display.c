#include "main.h"
/**
 * display - Displays the environment.
 * @envp: .......
 * Return: Always 0.
 */
int display(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
	return (0);
}
