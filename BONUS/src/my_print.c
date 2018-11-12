/*
** EPITECH PROJECT, 2018
** BONUS
** File description:
** my_print
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void x_case(int i)
{
    if (i % 2 == 0) {
        my_putstr(GRN);
        my_putchar('x');
        my_putstr(RESET);
    }
    else {
        my_putstr(RED);
        my_putchar('x');
        my_putstr(RESET);
    }
}

void my_print(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'x')
            x_case(i);
        else if (str[i] == 'o') {
            my_putstr(YEL);
            my_putchar('o');
            my_putstr(RESET);
        }
        else
            my_putchar(str[i]);
    }
}