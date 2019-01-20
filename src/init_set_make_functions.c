/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include "../includes/my.h"

void detect_colision(game_t *game, int i)
{
    sfVector2f pos_perso = sfSprite_getPosition(game->perso.sprite);
    sfVector2u size_perso = sfTexture_getSize(game->perso.texture);
    sfVector2f pos_obstacle = game->map[i]->pos;
    sfVector2u size_obstacle = sfTexture_getSize(game->map[i]->texture);

    if (pos_obstacle.x >= pos_perso.x && pos_obstacle.x <= pos_perso.x + \
    game->perso.rect.width / 2 && pos_perso.y <= pos_obstacle.y +
    size_obstacle.y && pos_perso.y + size_perso.y >= pos_obstacle.y) {
        if (game->id_obstacle != i && game->run != 0) {
            game->id_obstacle = i;
            game->nb_vie -= 1;
            sfMusic_play(game->perso.sound_hit);
            draw_the_new_life(game);
        } else if (game->id_obstacle != i && game->run == 0) {
            game->id_obstacle = i;
            game->nb_vie += 1;
            sfMusic_play(game->perso.sound_hit);
            draw_the_new_life(game);
        }
    }
}

void make_destroy(game_t game)
{
    sfSprite_destroy(game.background.sprite);
    sfSprite_destroy(game.background_soleil.sprite);
    sfSprite_destroy(game.background_ville3.sprite);
    sfSprite_destroy(game.background_ville2.sprite);
    sfSprite_destroy(game.background_ville1.sprite);
    sfSprite_destroy(game.background_ville0.sprite);
    sfSprite_destroy(game.background_tree.sprite);
    sfSprite_destroy(game.bg_menu.sprite);
    sfSprite_destroy(game.ground.sprite);
    sfSprite_destroy(game.perso.sprite);
    sfMusic_destroy(game.perso.sound_hit);
    sfMusic_destroy(game.song);
    sfText_destroy(game.name_game.text);
    sfText_destroy(game.play_text.text);
    sfText_destroy(game.exit_text.text);
    sfText_destroy(game.score.text);
    sfText_destroy(game.resume.text);
    sfText_destroy(game.menu_pause.text);
    sfRenderWindow_destroy(game.window);
}