#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

<<<<<<< HEAD
	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
=======
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
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
<<<<<<< HEAD
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
=======

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
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
<<<<<<< HEAD
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
=======
		dir = _getenv(info, "OLDPWD=");
		chdir_ret = chdir(dir ? dir : "/");
	}
	else
		chdir_ret = chdir((*info).argv[1]);
	if (chdir_ret == -1)
	{
		_eputs("cd: "), _eputs((*info).argv[1]), perror("");
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

<<<<<<< HEAD
	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
=======
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
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	return (0);
}
