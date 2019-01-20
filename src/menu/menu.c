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
#include "../../includes/my.h"

void manage_mouse_click_menu(sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse_position;
    sfUint8 nbr = 90;
    sfUint8 nbb = 255;
    mouse_position = sfMouse_getPosition((const sfWindow *)window);
    if (condition_manage_click_menu(game, 1, mouse_position) == 1) {
        sfText_setColor(game->play_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed && \
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->menu = 0;
    } else if (condition_manage_click_menu(game, 2, mouse_position) == 1) {
        sfText_setColor(game->exit_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(window);
    } else {
        sfText_setColor(game->play_text.text, (sfColor) {nbb, nbb, nbb, nbb});
        sfText_setColor(game->exit_text.text, (sfColor) {nbb, nbb, nbb, nbb});
    }
}

void manage_mouse_click_menu2(sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse_position;
    sfUint8 nbr = 90;
    sfUint8 nbb = 255;

    mouse_position = sfMouse_getPosition((const sfWindow *)window);
    if (condition_manage_click_menu2(game, 1, mouse_position) == 1) {
        sfText_setColor(game->resume.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed && \
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->menu = 0;
    } else if (condition_manage_click_menu2(game, 2, mouse_position) == 1) {
        sfText_setColor(game->exit_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(window);
    } else {
        sfText_setColor(game->resume.text, (sfColor) {nbb, nbb, nbb, nbb});
        sfText_setColor(game->exit_text.text, (sfColor) {nbb, nbb, nbb, nbb});
    }
}

void manage_mouse_click_defeat_vic(sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse_position;
    sfUint8 nbr = 90;
    sfUint8 nbb = 255;

    mouse_position = sfMouse_getPosition((const sfWindow *)window);
    if (condition_manage_click_vic_defeat(game, 1, mouse_position) == 1) {
        sfText_setColor(game->play_again.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed && \
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            set_value(game, 2);
    } else if (condition_manage_click_vic_defeat(game, 2, mouse_position)\
    == 1) {
        sfText_setColor(game->exit_text.text, (sfColor) {nbr, nbr, nbr, nbb});
        if (game->e_menu.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(window);
    } else {
        sfText_setColor(game->play_again.text, (sfColor) {nbb, nbb, nbb, nbb});
        sfText_setColor(game->exit_text.text, (sfColor) {nbb, nbb, nbb, nbb});
    }
}

void close_window_menu(sfRenderWindow *window, game_t *game)
{
    if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
    sfKeyEscape && game->menu != 1 && game->nb_vie > 0 && game->win == 0) {
        set_pos_menu_2(game);
        game->menu = 2;
    } if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
        sfKeyA && game->menu != 1)
        game->menu = 0;
    if (game->e_menu.type == sfEvtClosed || (game->e_menu.type ==
        sfEvtKeyPressed && game->e_menu.key.code == sfKeyQ))
        sfRenderWindow_close(window);
}

void analyse_events_menu(game_t *game)
{
    sfMouseButtonEvent mouse_event;

    while (sfRenderWindow_pollEvent(game->window, &game->e_menu)) {
        close_window_menu(game->window, game);
        if (game->menu == 1)
            manage_mouse_click_menu(game->window, game);
        if (game->menu == 2)
            manage_mouse_click_menu2(game->window, game);
        if (game->nb_vie == 0 || game->win == 1)
            manage_mouse_click_defeat_vic(game->window, game);
        manage_mouse_click(game);
    }
}