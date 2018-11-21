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

void my_memset(char *buffer, int i)
{
    data.buffer = my_strdup(buffer + i);
    data.adrex = 0;
    data.adrey = 0;
    data.max = 0;
    data.min = 0;
    data.value = 0;
    free(buffer);
}

int minint(int a, int b, int c)
{
    if (a <= b && a <= c)
        return (a);
    else if (b <= a && b <= c)
        return (b);
    else
        return (c);
}

void replace_buf_print(bsq_t *bsq, int max, int len, int j)
{
    for (int y = 0; y < max; ++y) {
        for (int x = 0; x < max; ++x, j--) {
            (bsq->buffer[j] != '\n' && bsq->buffer[j] != 'o') ?
            bsq->buffer[j] = 'x' : bsq->buffer[j];
        }
        j = j + max - len;
    }
    my_putstr(bsq->buffer);
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

void *my_algo(void *p)
{
    int i = 0;
    int len = data.i;
    (void)p;

    pthread_cond_wait(&data.synchro, &data.mut);
    pthread_mutex_unlock(&data.mut);
    my_memset(data.buffer, data.i);
    for (; data.buffer[len] != '\n'; len++);
    len++;
    for (int y = 1; data.tab && y < data.col; y++) {
        for (int x = 1; x < len; x++, i++) {
            (data.buffer[i] == '\n') ? i++ : i;
            (data.buffer[i] == 'o') ? data.tab[y][x] = 0 : i;
            my_algo_next(&data, y, i, x);
        }
    }
    replace_buf_print(&data, data.max, len, ((data.adrex - 1) +
    (data.adrey - 1) * len));
    pthread_mutex_lock(&data.mut);
    pthread_exit(NULL);
}