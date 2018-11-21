/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** main
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "../include/my.h"
#include "../include/bsq.h"

void *create(void *p)
{
    (void)p;

    pthread_mutex_lock(&data.mut);
    data.tab = malloc(sizeof(unsigned short *) * (data.col + 2));
    if (data.tab == NULL)
        return (NULL);
    for (int i = 0; i <= data.col; i++) {
        data.tab[i] = malloc(sizeof(unsigned short) * (data.len1 + 2));
        if (data.tab[i] == NULL)
            return (NULL);
        for (int j = 0; j <= data.len1; j++)
            data.tab[i][j] = 0;
    }
    pthread_mutex_unlock(&data.mut);
    sleep(1);
    pthread_cond_signal(&data.synchro);
    pthread_exit(NULL);
}

int len_second_line(char const *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    i++;
    return (i);
}

char *error_management(int ac, char *path)
{
    char *board = NULL;

    if (ac != 2)
        return (NULL);
    if ((board = get_tab(path)) == NULL)
        return (NULL);
    return (board);
}

int main(int ac, char **av)
{
    pthread_t alloc_tab;
    pthread_t algo;

    if ((data.buffer = error_management(ac, av[1])) == NULL)
        return (84);
    for (data.i = 0; data.buffer[data.i] != '\n'; ++data.i);
    data.i++;
    data.col = my_getnbr(data.buffer) + 1;
    data.len1 = len_second_line(data.buffer + data.i);
    pthread_create(&alloc_tab, NULL, create, &data);
    pthread_create(&algo, NULL, my_algo, &data);
    pthread_join(algo, NULL);
    pthread_join(alloc_tab, NULL);
    my_free();
    return (0);
}