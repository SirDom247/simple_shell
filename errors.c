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
