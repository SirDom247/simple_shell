#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

<<<<<<< HEAD
	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
=======
	for (i = 0; (src[i] != '\0') && (i < (n - 1)); i++)
	{
	    dest[i] = src[i];
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
<<<<<<< HEAD
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
=======
	int i, j = 0;
	char *s = dest;

>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
<<<<<<< HEAD
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
=======
 * *_strchr - ....
 *@s: .....
 *@c: ....
 * Return: ........
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
<<<<<<< HEAD

=======
>>>>>>> d54c3c596659b1cf94b72e69019619f0a4f685cd
	return (NULL);
}
