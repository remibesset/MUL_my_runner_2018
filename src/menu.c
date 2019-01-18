/*
** EPITECH PROJECT, 2018
** menu My Hunter
** File description:
** Menu
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"

void manage_mouse_click_menu(sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse_position;
    sfUint8 nbr = 90;
    sfUint8 nbb = 255;
    mouse_position = sfMouse_getPosition((const sfWindow *)window);
    //play
    if (mouse_position.x >= game->mode.width / 2 + 200 &&
    mouse_position.x <= game->mode.width / 2 + 200 + 5 * 50 &&
    mouse_position.y >= game->mode.height / 2 - 200 && mouse_position.y <=
    game->mode.height / 2 - 150) {
        sfText_setColor(game->play_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->event.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->menu = 0;
    //EXIT
    } else if (mouse_position.x >= game->mode.width / 2 + 190 &&
    mouse_position.x <= game->mode.width / 2 + 200 + 5 * 50 &&
    mouse_position.y > game->mode.height / 2 - 100 && mouse_position.y <=
    game->mode.height / 2 - 50) {
        sfText_setColor(game->exit_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->event.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(window);
    //OPTION
    } else if (mouse_position.x >= game->mode.width / 2 + 180 &&
    mouse_position.x <= game->mode.width / 2 + 180 + 8 * 50 &&
    mouse_position.y >= game->mode.height / 2 &&
    mouse_position.y <= game->mode.height / 2 + 50) {
        sfText_setColor(game->option_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->event.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            my_putstr("OPTION\n");
    } else {
        sfText_setColor(game->play_text.text, (sfColor) {nbb, nbb, nbb, nbb});
        sfText_setColor(game->exit_text.text, (sfColor) {nbb, nbb, nbb, nbb});
        sfText_setColor(game->option_text.text, (sfColor) {nbb, nbb, nbb, nbb});
    }
}

void close_window_menu(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtClosed || (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void analyse_events_menu(game_t *game)
{
    sfMouseButtonEvent mouse_event;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_window_menu(game->window, game);
        manage_mouse_click_menu(game->window, game);
    }
}