/*
** EPITECH PROJECT, 2019
** conditions of the menu on the pos of the mouse
** File description:
** pos mouse condition
*/

#include "../../includes/my.h"

int condition_manage_click_menu(game_t *game, int nbr,
sfVector2i mouse_position)
{
    int condition = 0;
    if (nbr == 1) {
        condition = mouse_position.x >= game->mode.width / 2 + 200 && \
        mouse_position.x <= game->mode.width / 2 + 200 + 5 * 50 && \
        mouse_position.y >= game->mode.height / 2 - 200 && mouse_position.y <=\
        game->mode.height / 2 - 150;
    } else if (nbr == 2) {
        condition = mouse_position.x >= game->mode.width / 2 + 190 && \
        mouse_position.x <= game->mode.width / 2 + 200 + 5 * 50 && \
        mouse_position.y > game->mode.height / 2 - 100 && mouse_position.y <= \
        game->mode.height / 2 - 50;
    }
    return (condition);
}

int condition_manage_click_menu2(game_t *game, int nbr,
sfVector2i mouse_position)
{
    int condition = 0;

    if (nbr == 1) {
        condition = mouse_position.x >= game->mode.width / 2 - 200 && \
        mouse_position.x <= game->mode.width / 2 - 200 + 8 * 50 && \
        mouse_position.y >= game->mode.height / 2 - 100 && mouse_position.y <= \
        game->mode.height / 2 - 50;
    } else if (nbr == 2) {
        condition = mouse_position.x >= game->mode.width / 2 - 190 && \
        mouse_position.x <= game->mode.width / 2 - 200 + 5 * 50 && \
        mouse_position.y > game->mode.height / 2 && mouse_position.y <= \
        game->mode.height / 2 + 50;
    }
    return (condition);
}

int condition_manage_click_vic_defeat(game_t *game, int nbr,
sfVector2i mouse_position)
{
    int condition = 0;

    if (nbr == 1) {
        condition = mouse_position.x >= game->mode.width / 2 - 300 && \
        mouse_position.x <= game->mode.width / 2 - 300 + 10 * 50 && \
        mouse_position.y >= game->mode.height / 2 && mouse_position.y <= \
        game->mode.height / 2 + 50;
    } else if (nbr == 2) {
        condition =mouse_position.x >= game->mode.width / 2 - 190 && \
        mouse_position.x <= game->mode.width / 2 - 100 + 5 * 50 && \
        mouse_position.y > game->mode.height / 2 + 100 && mouse_position.y <= \
        game->mode.height / 2 + 150;
    }
    return (condition);
}