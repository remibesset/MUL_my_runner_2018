/*
** EPITECH PROJECT, 2018
** My hunter project
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"
#include <SFML/Audio.h>

void make_run_perso(game_t *game)
{
    game->perso.time_st = sfClock_getElapsedTime(game->perso.clock_st);
    game->perso.second = game->perso.time_st.microseconds / 1000000.0;
    if (game->perso.second >= game->perso.max_sec) {
        game->perso.rect.left = 135 * (game->perso.i)++;
        game->perso.i = (game->perso.i > 5) ? 0 : game->perso.i;
        sfSprite_setTextureRect(game->perso.sprite, game->perso.rect);
        sfClock_restart(game->perso.clock_st);
    }
}

void do_paralax(init_sp_tex_t *background, game_t *game)
{
    int size = sfTexture_getSize(background->texture).x;

    background->time_st = sfClock_getElapsedTime(background->clock_st);
    background->second = background->time_st.microseconds / 1000000.0;
    if (background->second >= background->max_sec / 4) {
        background->pos.x -= background->speed;
        background->pos2.x -= background->speed;
        sfSprite_setPosition(background->sprite, background->pos);
        sfSprite_setPosition(background->sprite2, background->pos2);
        sfClock_restart(background->clock_st);
    }
    if (background->pos.x <= (-size / 2) - 250)
        background->pos.x = size / 2 + 250;
    if (background->pos2.x <= (-size / 2) - 250)
        background->pos2.x = size / 2 + 250;
}

int game_mode(int mode)
{
    game_t game;

    set_value(&game, 1);
    sfRenderWindow_setFramerateLimit(game.window, 160);
    while (sfRenderWindow_isOpen(game.window) == 1) {
        analyse_events_menu(&game);
        analyse_events(game.window, game);
        sfRenderWindow_clear(game.window, sfBlack);
        draw_all(game.window, &game);
    }
    make_destroy(game);
    return (0);
}
