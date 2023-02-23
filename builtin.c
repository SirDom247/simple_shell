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
        else
        {
            chdir_ret = chdir(dir);
        }
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
    {
        chdir_ret = chdir((*info).argv[1]);
    }
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


/**
 * unset_alias - .....
 * @info: .....
 * @str: ....
 *
 * Return: ...
 */
int unset_alias(info_t *info, char *str)
{
        char *p, c;
        int ret;

        p = _strchr(str, '=');
        if (!p)
                return (1);
        c = *p;
        *p = 0;
        ret = delete_node_at_index(&((*info).alias),
                get_node_index((*info).alias, node_starts_with((*info).alias, str, -1)));
        *p = c;
        return (ret);
}


/**
 * set_alias - .....
 * @info: ....
 * @str: ...
 *
 * Return: ......
 */
int set_alias(info_t *info, char *str)
{
        char *p;

        p = _strchr(str, '=');
        if (!p)
                return (1);
        if (!*++p)
                return (unset_alias(info, str));


        unset_alias(info, str);
        return (add_node_end(&(info->alias), str, 0) == NULL);
}


/**
 * print_alias - ....
 * @node: ...
 * Return: .....
 */
int print_alias(list_t *node)
{
        char *p = NULL, *a = NULL;

        if (node)
        {
                p = _strchr((*node).str, '=');
                for (a = (*node).str; a <= p; a++)
                _putchar(*a);
                _putchar('\'');
                _puts(p + 1);
                _puts("'\n");
                return (0);
        }
        return (1);
}


/**
 * _myalias - ....
 * @info: ....
 *  Return: .....
 */
int _myalias(info_t *info)
{
        int i = 0;
        char *p = NULL;
        list_t *node = NULL;


        if ((*info).argc == 1)
        {
                node = info->alias;
                while (node)
                {
                        print_alias(node);
                        node = (*node).next;
                }
                return (0);
        }
        for (i = 1; (*info).argv[i]; i++)
        {
                p = _strchr((*info).argv[i], '=');
                if (p)
                        set_alias(info, (*info).argv[i]);
                else
                        print_alias(node_starts_with(info->alias, (*info).argv[i], '='));
        }
        return (0);
}
