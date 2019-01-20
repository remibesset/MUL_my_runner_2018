/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw
*/

#include "../../includes/my.h"

void draw_the_new_life(game_t *game)
{
    char *score_to_char = my_revstr(conv_i_str(game->nb_vie + ((game->run == 0)\
    ? -1 : 0)));
    char *strcat_char = (game->run == 0) ? my_strcat("HIT: ", score_to_char)\
: my_strcat("LIFE: ", score_to_char);
    sfText_setString(game->vie_text.text, strcat_char);
    free(strcat_char);
    free(score_to_char);
    sfMusic_setLoop(game->song, sfTrue);
    sfMusic_play(game->song);
}

void draw_map(game_t *game)
{
    int i = 0;
    float nb = (float) game->mode.width / 2 - 150;

    for (i; game->map[i] != NULL; i++) {
        game->map[i]->pos.x -= 2.5 + game->speed_increase;
        detect_colision(game, i);
        sfSprite_setPosition(game->map[i]->sprite, game->map[i]->pos);
        sfRenderWindow_drawSprite(game->window, game->map[i]->sprite, NULL);
        if (game->run != 0 && game->map[i]->pos.x < 0 && game->map[i]->type ==\
        2) {
            game->win = 1;
            draw_defeat(game, 0);
        }
    }
    i--;
    for (int j = 0; game->map[j] != NULL && game->run == 0; j++) {
        if (game->map[i]->pos.x < -nb) {
            game->map[j]->pos.x = game->map[j]->pos_base.x;
        }
    }
}

void draw_defeat(game_t *game, int mode)
{
    if (mode == 1)
        sfText_setString(game->victory_defeat.text, "DEFEAT");
    sfRenderWindow_drawText(game->window, game->victory_defeat.text, NULL);
    game->score.pos_text.x = game->mode.width / 2 - 200;
    game->score.pos_text.y = game->mode.height / 2 - 200;
    sfText_setCharacterSize(game->score.text, 40);
    sfText_setPosition(game->score.text, game->score.pos_text);
    sfRenderWindow_drawText(game->window, game->score.text, NULL);
    load_file_in_memo("includes/score.txt", game);
    game->exit_text.pos_text.x = game->mode.width / 2 - 120;
    game->exit_text.pos_text.y = game->mode.height / 2 + 100;
    sfText_setPosition(game->exit_text.text, game->exit_text.pos_text);
    sfRenderWindow_drawText(game->window, game->exit_text.text, NULL);
    sfRenderWindow_drawText(game->window, game->play_again.text, NULL);
}

void draw_all(sfRenderWindow *window, game_t *game)
{
    draw_parallax(window, game);
    if (game->slide == 1)
        make_the_slide(game);
    else if (game->jump == 1) {
        make_jump_perso(game);
    } else
        make_run_perso(game);
    sfRenderWindow_drawSprite(window, game->perso.sprite, NULL);
    if (game->menu == 1) {
        draw_menu1(game);
    } else {
        draw_map(game);
    }
}