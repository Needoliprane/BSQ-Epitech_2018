/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** main
*/

#include <stdlib.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/bsq.h"

int my_strlenbsq(char const *str)
{
    int i = 0;
    int j = 0;

    for (;str[i] != '\n'; i++);
    j = i;
    i++;
    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return (i - j);
}

int main(int ac, char **av)
{
    char *board = NULL;
    int i = 0;
    int c = 0;
    int l = 0;

    if (ac != 2)
        return (84);
    if ((board = get_tab(av[1])) == NULL)
        return (84);
    for (; board[i] != '\n'; i++);
    i++;
    c = my_strlenbsq(board);
    l = my_getnbr(board) + 1;
    my_algo(board + i, c, l, create(l, c));
    free(board);
    return (0);
}