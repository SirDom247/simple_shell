#include "main.h"
/**
 * _which - searches for a command in the PATH environment variable
 *
 * @argv: the command to search for
 *
 * Return: a string containing the full path to the command, or NULL if it
 * could not be found
 */

char *_which(char *argv)
{
	char path[BUFSIZE];
	struct stat st;

	snprintf(path, BUFSIZE, "%s", argv);

	if (stat(path, &st) == 0)
	{
		printf("this is the %s\n", path);
		return (strdup(path));
	}
	else
	{
		char *p = getenv("PATH");

		if (p != NULL)
		{
			char *dir = strtok(p, ":");

			while (dir != NULL)
			{
				memset(path, 0, sizeof(path));
				snprintf(path, BUFSIZE, "%s/%s", dir, argv);
				if (stat(path, &st) == 0)
				{
					printf("this is path %s\n", path);
					return (strdup(path));
				}
				dir = strtok(NULL, ":");
			}
			p = NULL;
		}
	}
	return (NULL);
}

