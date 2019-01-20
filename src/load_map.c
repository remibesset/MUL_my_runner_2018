/*
** EPITECH PROJECT, 2019
** load map
** File description:
** map
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/my.h"

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

char **my_realloc_charchar(char **list, char *name)
{
    char **new = malloc(sizeof(char *) * (my_strlen_char(list) + 2));
    int i = 0;
    int j = 0;

    for (i; list[i][0] != '\0'; i++) {
        new[j] = list[i];
        j++;
    }
    new[i] = name;
    new[i + 1] = "\0";
    free(list);
    return (new);
}

sprite_map_t **my_realloc_struct(sprite_map_t **list, sprite_map_t *name)
{
    sprite_map_t **new = malloc(sizeof(sprite_map_t *) *\
    (my_strlen_liste(list) + 2));
    int i = 0;
    int j = 0;

    for (i; list[i] != NULL; i++) {
        new[j] = list[i];
        j++;
    }
    new[i] = name;
    new[i + 1] = NULL;
    free(list);
    return (new);
}

sprite_map_t *new_object(int i, int j, int num, game_t *game)
{
    sprite_map_t *object_st = malloc(sizeof(sprite_map_t) * 1);
    char *src;
    int hauteur = 475;

    src = (num == 1) ? "includes/images/player/ninja_enemy.png" : src;
    src = (num == 3) ? "includes/images/player/obstacle_up.png" : src;
    src = (num == 2) ? "includes/images/player/obstacle_down.png" : src;
    hauteur = (num == 2) ? 230 : hauteur;
    hauteur = (num == 3) ? 510: hauteur;
    object_st->pos_base = (sfVector2f) {j * 45 + game->mode.width, hauteur};
    object_st->pos = (sfVector2f) {j * 45 + game->mode.width, hauteur};
    object_st->texture = sfTexture_createFromFile(src, NULL);
    object_st->sprite = sfSprite_create();
    object_st->type = 1;
    sfSprite_setTexture(object_st->sprite, object_st->texture, sfTrue);
    sfSprite_setPosition(object_st->sprite, object_st->pos);
    return (object_st);
}

sprite_map_t **complete_list(char **buff, sprite_map_t **list, game_t *game)
{
    for (int i = 0; buff[i][0] != '\0'; i++)
        for (int j = 0; buff[i][j] != '\0'; j++) {
            list = (buff[i][j] == '1') ?\
        my_realloc_struct(list, new_object(i, j, 1, game)) : list;
            list = (buff[i][j] == '2') ?\
            my_realloc_struct(list, new_object(i, j, 2, game)) : list;
            list = (buff[i][j] == '3') ?\
        my_realloc_struct(list, new_object(i, j, 3, game)) : list;
        }
    return (list);
}

sprite_map_t **load_file(char *filepath, game_t *game)
{
    sprite_map_t **list = malloc(sizeof(sprite_map_t *) * 1);
    FILE *fd = fopen(filepath, "r");
    char *line = NULL;
    char *buff_line = malloc(sizeof(char) * 1);
    size_t len = 0;
    ssize_t read;
    char **buff = malloc(sizeof(char *) * 1);
    int i = 0;

    buff[0] = "\0";
    list[0] = NULL;
    buff_line[0] = '\0';
    while ((read = getline(&line, &len, fd)) != -1) {
        buff_line = malloc(sizeof(char) * (read + 1));
        for (i = 0; line[i] != '\0'; i++)
            buff_line[i] = line[i];
        buff_line[i] = '\0';
        buff = my_realloc_charchar(buff, buff_line);
    }
    list = complete_list(buff, list, game);
    return (list);
}