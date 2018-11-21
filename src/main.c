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

unsigned short **create(int hei, int len)
{
    unsigned short **tab = malloc(sizeof(unsigned short *) * (hei + 1));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i <= hei; i++) {
        tab[i] = malloc(sizeof(unsigned short) * (len + 1));
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

int check_board(char *str, int i)
{
    for (int j = 0; str[j] && str[j] != '\n'; j++) {
        if (str[j] < '0' || str[j] > '9')
            return (84);
    }
    for (int j = i; str[j]; j++) {
        if (str[j] != '.' && str[j] != '\n' && str[j] != 'o')
            return (84);
    }
    return (0);
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
    if (check_board(board, i) == 84)
        return (84);
    my_algo(board + i, my_getnbr(board) + 1, len_second_line(board + i));
    free(board);
    return (0);
}