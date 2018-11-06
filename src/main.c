/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/bsq.h"

int **create(int hei, int len)
{
    int **tab = malloc(sizeof(int *) * (hei + 1));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i <= hei; i++) {
        tab[i] = malloc(sizeof(int) * (len + 1));
        if (tab[i] == NULL)
            return (NULL);
        for (int j = 0; j <= len; j++)
            tab[i][j] = 0;
    }
    return (tab);
}

int len_second_line(char const *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    i++;
    return (i);
}

int main(int ac, char **av)
{
    char *board = NULL;
    int i = 0;

    if (ac != 2)
        return (84);
    if ((board = get_tab(av[1])) == NULL)
        return (84);
    for (; board[i] != '\n'; i++);
    i++;
    my_algo(board + i, my_getnbr(board) + 1, len_second_line(board + i));
    free(board);
    return (0);
}