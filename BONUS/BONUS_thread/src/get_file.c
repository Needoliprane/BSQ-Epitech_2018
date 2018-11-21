/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** get_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

int get_fd(char const *str)
{
    int fd = 0;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        my_putstr("Error : file doesn't exist");
    return (fd);
}

long size_to_read(char const*path)
{
    int c_state = 0;
    struct stat file;

    c_state = stat(path, &file);
    if (c_state == -1) {
        my_putstr("Error : stat fail");
        return (0);
    }
    return (file.st_size);
}

char *my_read(int fd, char const *path)
{
    int c_read = 0;
    long size = size_to_read(path);
    char *str = malloc(sizeof(char) * (size + 2));

    str[size] = '\0';
    c_read = read(fd, str, size);
    if (c_read == -1) {
        my_putstr("Error : read fail");
        return (NULL);
    }
    return (str);
}

char *get_tab(char const *str)
{
    int fd = get_fd(str);
    char *read = NULL;

    if (fd == -1)
        return (NULL);
    read = my_read(fd, str);
    if (read == NULL)
        return (NULL);
    if (read[0] == '\0' || read[1] == '\0')
        return (NULL);
    close(fd);
    return (read);
}