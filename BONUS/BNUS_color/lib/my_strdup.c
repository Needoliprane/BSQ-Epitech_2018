/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        my_putstr("Error : malloc fail");
        return (NULL);
    }
    for (; dest && src[i]; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}