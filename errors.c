#include "shell.h"
/**
 * _eputs - .....
 * @str: .....
 *
 * Return: ....
 */
void _eputs(char *str)
{
        int i = 0;

        if (!str)
                return;
        for (i = 0; str[i] != '\0'; i++)
        {
            _eputchar(str[i]);
        }
}



/**
 * _eputchar - ....
 * @c: ...
 * Return: ....
  */
int _eputchar(char c)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(2, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}


/**
 * _putfd - ...
 * @c: ...
 * @fd:...
 * Return: ...
 */
int _putfd(char c, int fd)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(fd, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}


/**
 * _putsfd - ...
 * @str: ....
 * @fd: ....
 *
 * Return:....
 */
int _putsfd(char *str, int fd)
{
        int i = 0;


        if (!str)
                return (0);
        while (*str)
        {
                i += _putfd(*str++, fd);
        }
        return (i);
}


/**
 * _erratoi - ....
 * @s: ....
 * Return: ....
 */
int _erratoi(char *s)
{
        int i = 0;
        unsigned long int result = 0;


        if (*s == '+')
                s++;
        for (i = 0;  s[i] != '\0'; i++)
        {
                if (s[i] >= '0' && s[i] <= '9')
                {
                        result *= 10;
                        result += (s[i] - '0');
                        if (result > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (result);
}


/**
 * print_error - .....
 * @info: ....
 * @estr: ....
 * Return: ....
 */
void print_error(info_t *info, char *estr)
{
        _eputs((*info).fname);
        _eputs(": ");
        print_d((*info).line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs((*info).argv[0]);
        _eputs(": ");
        _eputs(estr);
}


/**
 * print_d - ....
 * @input: .....
 * @fd: ....
 * Return: .....
 */
int print_d(int input, int fd)
{
        int (*__putchar)(char) = _putchar;
        int i, count = 0;
        unsigned int _abs_, current;


        if (fd == STDERR_FILENO)
                __putchar = _eputchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                count++;
        }
        else
                _abs_ = input;
        current = _abs_;
        for (i = 1000000000; i > 1; i /= 10)
        {
                if (_abs_ / i)
                {
                        __putchar('0' + current / i);
                        count++;
                }
                current %= i;
        }
        __putchar('0' + current);
        count++;

        return (count);
}


/**
 * convert_number - ....
 * @num: ...
 * @base: ....
 * @flags: ....
 * Return: ....
 */
char *convert_number(long int num, int base, int flags)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                n = -num;
                sign = '-';


        }
        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';

        do        {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);


        if (sign)
                *--ptr = sign;
        return (ptr);
}


/**
 * remove_comments - ....
 * @buf: .....
 * Return: ...
 */
void remove_comments(char *buf)
{
        int i;
        
        for (i = 0; buf[i] != '\0'; i++)
                if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
                {
                        buf[i] = '\0';
                        break;
                }
}