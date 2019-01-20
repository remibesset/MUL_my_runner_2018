/*
** EPITECH PROJECT, 2018
** My hunter project
** File description:
** my_hunter
*/

#include "../includes/my.h"
void make_run_perso(game_t *game)
{
    if (game->perso.pos.x > 100)
        game->perso.pos.x -= 1;
    if (game->perso.pos.y != 475)
        game->perso.pos.y = 475;
    sfSprite_setPosition(game->perso.sprite, game->perso.pos);
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
    if (background->second >= background->max_sec) {
        background->pos.x -= background->speed + game->speed_increase;
        background->pos2.x -= background->speed + game->speed_increase;
        sfSprite_setPosition(background->sprite, background->pos);
        sfSprite_setPosition(background->sprite2, background->pos2);
        sfClock_restart(background->clock_st);
    }
    if (background->pos.x <= (-size / 2) - 250)
        background->pos.x = size / 2 + 250;
    if (background->pos2.x <= (-size / 2) - 250)
        background->pos2.x = size / 2 + 250;
    if (game->score.score % 400 == 200 && game->run == 0)
        game->speed_increase += 0.01;
}

int game_mode(int mode, char *filepath)
{
    game_t game;

    game.filepath = (filepath[0] == '\0') ? "map.txt" : filepath;
    if (set_value(&game, mode) == 84)
        return (84);
    sfRenderWindow_setFramerateLimit(game.window, 120);
    while (sfRenderWindow_isOpen(game.window) == 1) {
        analyse_events_menu(&game);
        if (game.menu != 2 && game.nb_vie > 0 && game.win == 0) {
            sfRenderWindow_clear(game.window, sfBlack);
            draw_all(game.window, &game);
        } else if (game.menu == 2)
            draw_menu2(&game);
        else
            draw_defeat(&game, (game.win == 1) ? 0 : 1);
        if (game.nb_vie > 0 && game.menu == 0 && game.win == 0)
            draw_text(&game);
        sfRenderWindow_display(game.window);
    }
    make_destroy(game);
    return (0);
}