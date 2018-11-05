/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** bqs
*/

#ifndef BQS_H_
#define BQS_H_

/* MY ALGO */

void my_algo(char *tab, int hei, int len, int **tb);
int **create(int hei, int len);

/* GET THE BOARD */

char *get_tab(char const *str);
char *my_read(int fd, char const *path);
int get_fd(char const *str);
long size_to_read(char const*path);

#endif /* !BQS_H_ */