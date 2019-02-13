/*
** EPITECH PROJECT, 2019
** utilliest function
** File description:
** utils function
*/

#include "../includes/my.h"

char *my_strcpy(char *dest, char const *src, int i)
{
    int j = 0;

    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char const *a, char const *b)
{
    char *new_char = xmalloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));

    new_char = my_strcpy(new_char, a, 0);
    new_char = my_strcpy(new_char, b, my_strlen(a));
    return (new_char);
}

char *conv_i_str(int nbr)
{
    char *result = xmalloc(sizeof(char) * (11 + 1));
    int i = 0;

    if (nbr > 0) {
        while (nbr != 0) {
            result[i++] = nbr % 10 + '0';
            nbr /= 10;
        }
    } else
        result[i++] = '0';
    result[i] = '\0';
    return (result);
}

int my_strlen_liste(sprite_map_t **list)
{
    int i = 0;

    for (i = 0; list[i] != NULL; i++);
    return (i);
}

int my_strlen_char(char **list)
{
    int i = 0;

    for (i = 0; list[i][0] != '\0'; i++);
    return (i);
}