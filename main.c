#include "main.h"

/**
 * main - Entry point for the simple shell program
 * @argc: ......
 * @argv: .....
 * @envp: .....
 * Return: 0 on successful completion of the program
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	shell_loop(envp);
	return (0);
}
