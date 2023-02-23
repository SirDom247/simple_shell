#include "shell.h"
/**
 * input_buf - ....
 * @info: ...
 * @buf: .....
 * @len: ....
 *
 * Return: ....
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
        ssize_t r = 0;
        size_t len_p = 0;


        if (!*len)
        {
                free(*buf);
                *buf = NULL;
                signal(SIGINT, sigintHandler);
                r = getline(buf, &len_p, stdin);
                r = _getline(info, buf, &len_p);

                if (r > 0)
                {
                        if ((*buf)[r - 1] == '\n')
                        {
                                (*buf)[r - 1] = '\0';
                                r--;
                        }
                        (*info).linecount_flag = 1;
                        remove_comments(*buf);
                        build_history_list(info, *buf, (*info).histcount++);
                        {
                                *len = r;
                                (*info).cmd_buf = buf;
                        }
                }
        }
        return (r);
}