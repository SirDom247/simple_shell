#include "shell.h"
/**
 **_strncpy - ...
 *@dest: ...
 *@src: ....
 *@n: .....
 *Return: ...
 */
char *_strncpy(char *dest, char *src, int n)
{
        int i, j;
        char *s = dest;

        for (i = 0; src[i] != '\0' && i < n - 1; i++)
        {
            dest[i] = src[i];
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
 **_strncat - ...
 *@dest: ....
 *@src: ....
 *@n: ...
 *Return: ....
 */
char *_strncat(char *dest, char *src, int n)
{
        int i, j = 0;
        char *s = dest;

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
 **_strchr - ....
 *@s: .....
 *@c: ....
 */
char *_strchr(char *s, char c)
{
        do {
                if (*s == c)
                        return (s);
        } while (*s++ != '\0');


        return (NULL);
}