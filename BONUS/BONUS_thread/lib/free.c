/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include "bsq.h"
#include "my.h"

void my_free(void)
{
    for (int i = 0; i <= data.len1; i++)
        free(data.tab[i]);
    free(data.buffer);
    free(data.tab);
}