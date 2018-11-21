/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (write(1, "--null--\n", 5));
    for (; str[i]; i++);
    write(1, str, i);
    return (0);
}

int my_show_word_array(char **tab)
{
    for (int i = 0; tab && tab[i]; i++)
        my_putstr(tab[i]);
    return (0);
}