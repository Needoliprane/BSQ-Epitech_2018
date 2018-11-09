/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include "bsq.h"
#include "my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab && tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void free_express(int *t, char **numbers)
{
    free(t);
    free_tab(numbers);
}

void free_tab_int(unsigned short **tab, int hei, bsq_t *bsq)
{
    if (tab == NULL)
        exit(84);
    for (int i = 0; i <= hei; i++)
        free(tab[i]);
    free(tab);
    free(bsq->buffer);
    free(bsq);
}