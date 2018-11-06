/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_algo
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

void my_memset(bsq_t *bsq, char *buffer)
{
    bsq->buffer = my_strdup(buffer);
    bsq->adrex = 0;
    bsq->adrey = 0;
    bsq->max = 0;
    bsq->min = 0;
    bsq->value = 0;
}

int minint(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1)
        return (0);
    if (a <= b && a <= c)
        return (a);
    else if (b <= a && b <= c)
        return (b);
    else
        return (c);
}

void replace_buf_print(char *buf, int max, int len, int j)
{
    for (int y = 0; y < max; ++y) {
        for (int x = 0; x < max; ++x, j--) {
            (buf[j] != '\n' && buf[j] != 'o') ? buf[j] = 'x' : buf[j];
        }
        j = j + max - len;
    }
    my_putstr(buf);
}

void my_algo_next(bsq_t *bsq, int y, int i, int x)
{
    if (bsq->buffer[i] == '.' && y >= 1 && x >= 1) {
        bsq->min = minint(bsq->tab[y - 1][x], bsq->tab[y][x - 1],
        bsq->tab[y - 1][x - 1]);
        bsq->tab[y][x] = bsq->min + 1;
        bsq->value = bsq->min + 1;
        (bsq->max < bsq->value) ? ((bsq->max = bsq->value), (bsq->adrex = x),
        (bsq->adrey = y)) : x;
    }
}

void my_algo(char *buffer, int hei, int len)
{
    bsq_t *bsq = malloc(sizeof(bsq_t));
    int i = 0;

    bsq->tab = create(hei, len);
    bsq->len = len;
    my_memset(bsq, buffer);
    for (int y = 1; bsq->tab && y < hei; ++y) {
        for (int x = 1; x < len; ++x, i++) {
            (buffer[i] == '\n') ? i++ : i;
            (buffer[i] == 'o') ? bsq->tab[y][x] = 0 : i;
            my_algo_next(bsq, y, i, x);
        }
    }
    replace_buf_print(bsq->buffer, bsq->max, len, ((bsq->adrex - 1) + (bsq->adrey - 1) * len));
    free_tab_int(bsq->tab, hei, bsq);
}
//    write(1, buffer, ((len) * (hei - 1)));