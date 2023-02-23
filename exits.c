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