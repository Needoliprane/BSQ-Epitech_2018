/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#ifndef MY_H_
#define MY_H_

/* define */

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/* LIB */

char *my_revstr(char *str);
int my_show_word_array(char **tab);
int my_getnbr(char const *str);
char **my_str_to_word_array(char const *str);
int count_para(char const *str, char c);
char *check_tmp(char *tmp, char const *str);
int my_putstr(char const *str);
void free_tab(char **tab);
int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_strlen_tab(char **av);
int my_put_nbr(int nb);
void my_putchar(char c);

#endif