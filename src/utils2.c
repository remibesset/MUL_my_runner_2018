/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc
*/

#include "../includes/my.h"

void *xmalloc(int size)
{
    void *ptr = malloc(size);
    char err_msg[] = "Malloc failed !\n";

    if (ptr == NULL) {
        write(2, err_msg, my_strlen(err_msg));
        exit(84);
    }
    return (ptr);
}
