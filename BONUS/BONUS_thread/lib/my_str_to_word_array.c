/*
** EPITECH PROJECT, 2018
** str
** File description:
** str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_num_alpha(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') || c == '.' || c == 'o')
        return (0);
    return (1);
}

char **my_word_to_array(char **argv, char const *str)
{
    int j = 0;
    int c = 0;

    for (int i = 0; str[i]; i++) {
        if (is_num_alpha(str[i]) == 0) {
            argv[j][c] = str[i];
            c++;
        }
        if (c != 0 && (is_num_alpha(str[i]) == 1 &&
            is_num_alpha(str[i + 1] == 0)) ) {
            argv[j][c] = '\0';
            j++;
            c = 0;
        }
    }
    argv[j + 1] = NULL;
    return (argv);
}

char **my_str_to_word_array(char const *str)
{
    char **argv = NULL;
    int j = 0;

    if (str[0] == 0)
        return (NULL);
    for (int i = 0; str && str[i]; i++)
        if (is_num_alpha(str[i]) == 1 && is_num_alpha(str[i + 1]) == 0)
            j++;
    if ((argv = malloc(sizeof(char *) * (j + 3))) == NULL)
        return (NULL);
    for (int i = 0; i <= j; i++) {
        argv[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (argv[i] == NULL)
            return (NULL);
        for (int c = 0; c <= my_strlen(str); c++)
            argv[i][c] = '\0';
    }
    return (my_word_to_array(argv, str));
}