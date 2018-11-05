/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_algo
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

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

int **create(int hei, int len)
{
    int **tab = malloc(sizeof(int *) * (hei + 1));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i <= hei; i++) {
        tab[i] = malloc(sizeof(int) * (len + 1));
        if (tab[i] == NULL)
            return (NULL);
    }
    return (tab);
}

void my_algo(char *buffer, int hei, int len, int **tab)
{
    int max = 0;
    int adrex = 0;
    int adrey = 0;

    my_putstr(buffer);
    for (int y = 1, value = 0, i = 0, min = 0; tab && y < hei; ++y) {
        for (int x = 1; x < len; ++x, i++) {
            (buffer[i] == '\n') ? i++ : i;
            (buffer[i] == 'o') ? tab[y][x] = 0 : i;
            if (buffer[i] == '.' && y >= 1 && x >= 1) {
                min = minint(tab[y - 1][x], tab[y][x - 1], tab[y - 1][x - 1]);
                tab[y][x] = min + 1;
                value = min + 1;
                (max < value) ? ((max = value), (adrex = x), (adrey = y)) : x;
            }
        }
    }
    free_tab_int(tab, hei);
    replace_buf_print(buffer, max, len, ((adrex - 1) + (adrey - 1) * len));
}
//    write(1, buffer, ((len) * (hei - 1)));