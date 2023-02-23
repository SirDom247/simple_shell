#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
<<<<<<< HEAD
	print_list_str(info->env);
=======
	print_list_str((*info).env);
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
<<<<<<< HEAD
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
=======
	list_t *node = (*info).env;
	char *p;


	while (node)
	{
		p = starts_with((*node).str, name);
		if (p && *p)
			return (p);
		node = (*node).next;
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
<<<<<<< HEAD
	if (info->argc != 3)
=======
	if ((*info).argc != 3)
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
<<<<<<< HEAD
	if (_setenv(info, info->argv[1], info->argv[2]))
=======
	if (_setenv(info, (*info).argv[1], (*info).argv[2]))
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;
<<<<<<< HEAD
=======

	if ((*info).argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= (*info).argc; i++)
		_unsetenv(info, (*info).argv[i]);
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;
<<<<<<< HEAD

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
=======


	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	(*info).env = node;
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	return (0);
}
