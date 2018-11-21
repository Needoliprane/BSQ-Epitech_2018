/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** bqs
*/

#ifndef BQS_H_
#define BQS_H_

/* INCLUDE */

#include <pthread.h>

/* STRUCT */

typedef struct bsq_s
{
    char *buffer;
    unsigned short **tab;
    int col;
    int len1;
    int max;
    int min;
    int adrey;
    int adrex;
    int len;
    int value;
    int i;
    pthread_cond_t synchro;
    pthread_mutex_t mut;
} bsq_t;

extern bsq_t data;

/* MY ALGO */

void *my_algo(void *);

/* GET THE BOARD */

char *get_tab(char const *str);
char *my_read(int fd, char const *path);
int get_fd(char const *str);
long size_to_read(char const*path);

#endif /* !BQS_H_ */