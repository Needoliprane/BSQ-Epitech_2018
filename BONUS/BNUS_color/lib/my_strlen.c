/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

int my_strlen_tab(char **av)
{
    int i = 0;

    for (; av && av[i]; i++);
    return (i);
}