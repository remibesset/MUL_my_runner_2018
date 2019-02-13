/*
** EPITECH PROJECT, 2018
** event csfml
** File description:
** csfml
*/

#include "../includes/my.h"

void change_font(game_t *game, char *filepath_font, int mode)
{
    sfVector2u get_size;

    sfTexture_destroy(game->perso.texture);
    init_first_change_font(game, filepath_font, mode);
    if (mode == 2 && game->jump == 1) {
        game->perso.rect = (sfIntRect) {0, 0, 910, 135};
        game->perso.texture = sfTexture_createFromFile(filepath_font, \
        &game->perso.rect);
        game->perso.rect.width = 135;
        game->perso.max_sec = 0.1;
    }
    game->perso.i = 0;
    sfSprite_setTexture(game->perso.sprite, game->perso.texture, sfTrue);
    sfSprite_setPosition(game->perso.sprite, game->perso.pos);
}

void make_the_slide(game_t *game)
{
    game->perso.time_st = sfClock_getElapsedTime(game->perso.clock_st);
    game->perso.second = game->perso.time_st.microseconds / 1000000.0;
    if (game->perso.second >= game->perso.max_sec - game->speed_increase \
    / 10) {
        change_font(game, "includes/images/player/nin_run.png", 0);
        game->slide = 0;
    }
}

void do_the_jump_pos(game_t *game)
{
    if (game->perso.i < 3) {
        game->perso.pos.y -= 5.0;
        game->perso.pos.x += 0.5;
    } else if (game->perso.i > 4) {
        game->perso.pos.y += 5.0;
        game->perso.pos.x += 0.5;
    }
    sfSprite_setPosition(game->perso.sprite, game->perso.pos);
}

void make_jump_perso(game_t *game)
{
    game->perso.time_st = sfClock_getElapsedTime(game->perso.clock_st);
    game->perso.second = game->perso.time_st.microseconds / 1000000.0;
    do_the_jump_pos(game);
    if (game->perso.second >= game->perso.max_sec - (game->speed_increase /\
    100)) {
        game->perso.rect.left = 133 * (game->perso.i)++;
        game->perso.i = (game->perso.i > 6) ? 0 : game->perso.i;
        if (game->perso.i == 0) {
            game->perso.pos.y += 25.0;
            change_font(game, "includes/images/player/nin_run.png", 0);
            game->jump = 0;
        }
        sfSprite_setTextureRect(game->perso.sprite, game->perso.rect);
        sfClock_restart(game->perso.clock_st);
    }
}

int manage_mouse_click(game_t *game)
{

    if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
    sfKeySpace && game->jump == 0 && game->slide != 1 && game->nb_vie > 0 && \
    game->win == 0) {
        game->jump = 1;
        change_font(game, "includes/images/player/nin_jump.png", 2);
        sfSprite_setTexture(game->perso.sprite, game->perso.texture, sfTrue);
    }
    else if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
    sfKeyDown && game->slide == 0 && game->jump != 1 && game->nb_vie > 0 && \
    game->win == 0) {
        game->slide = 1;
        change_font(game, "includes/images/player/nin_slide.png", 1);
        //sfSprite_setTexture(game->perso.sprite, game->perso.texture, sfTrue);
    }
}