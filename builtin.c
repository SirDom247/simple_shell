#include "shell.h"
/**
 * _myexit - .....
 * @info: ....
 * constant ....
 * Return: ....
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if ((*info).argv[1])
	{
		exitcheck = _erratoi((*info).argv[1]);
		if (exitcheck == -1)
		{
			(*info).status = 2;
			print_error(info, "Illegal number: ");
			_eputs((*info).argv[1]);
			_eputchar('\n');
			return (1);
		}
		(*info).err_num = _erratoi((*info).argv[1]);
		return (-2);
	}
	(*info).err_num = -1;
	return (-2);
}


/**
 * _mycd - ....
 * @info: .....
 * Return: .....
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);

	if (!s)
		_eputs("getcwd failed"), perror("");
	if (!(*info).argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
		{
			chdir_ret = chdir("/");
		}
		chdir_ret = chdir(dir);
	}
	else if (_strcmp((*info).argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		dir = _getenv(info, "OLDPWD=");
		chdir_ret = chdir(dir ? dir : "/");
	}
	else
		chdir_ret = chdir((*info).argv[1]);
	if (chdir_ret == -1)
	{
		_eputs("cd: "), _eputs((*info).argv[1]), perror("");
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - ....
 * @info: ....
 * constant ....
 * Return: .....
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = (*info).argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}


/**
 * _myhistory - ...
 * @info: ....
 * Return: ...
 */
int _myhistory(info_t *info)
{
	print_list((*info).history);
	return (0);
}
