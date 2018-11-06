/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** bqs
*/

#ifndef BQS_H_
#define BQS_H_

/* STRUCT */

typedef struct bsq_s
{
    char *buffer;
    int **tab;
    int max;
    int min;
    int adrey;
    int adrex;
    int len;
    int value;
} bsq_t;


/* MY ALGO */

void my_algo(char *tab, int hei, int len);
int **create(int hei, int len);

/* GET THE BOARD */

char *get_tab(char const *str);
char *my_read(int fd, char const *path);
int get_fd(char const *str);
long size_to_read(char const*path);

/* FREE */

void free_tab_int(int **tab, int hei, bsq_t *bsq);

#endif /* !BQS_H_ */