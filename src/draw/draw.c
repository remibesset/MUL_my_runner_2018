/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw
*/

#include "../../includes/my.h"

void draw_with_paralax(sfRenderWindow *window, init_sp_tex_t *display, \
game_t *game)
{
    do_paralax(display, game);
    sfRenderWindow_drawSprite(window, display->sprite, NULL);
    sfRenderWindow_drawSprite(window, display->sprite2, NULL);
}

void draw_parallax(sfRenderWindow *window, game_t *game)
{
    set_scale(game);
    sfRenderWindow_drawSprite(window, game->background.sprite, NULL);
    draw_with_paralax(window, &game->background_soleil, game);
    draw_with_paralax(window, &game->background_ville3, game);
    draw_with_paralax(window, &game->background_ville2, game);
    draw_with_paralax(window, &game->background_ville1, game);
    draw_with_paralax(window, &game->background_ville0, game);
    draw_with_paralax(window, &game->background_tree, game);
    draw_with_paralax(window, &game->ground, game);
}

void draw_menu1(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->name_game.text, NULL);
    sfRenderWindow_drawText(game->window, game->play_text.text, NULL);
    sfRenderWindow_drawText(game->window, game->exit_text.text, NULL);
}

void draw_menu2(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->menu_pause.text, NULL);
    sfRenderWindow_drawText(game->window, game->resume.text, NULL);
    sfRenderWindow_drawText(game->window, game->exit_text.text, NULL);
}

void draw_text(game_t *game)
{
    game->score.score = game->score.score + 1;
    game->score.text_char = my_revstr(conv_i_str(game->score.score / 4));
    char *strcat_char = my_strcat("SCORE: ", game->score.text_char);
    sfText_setString(game->score.text, strcat_char);
    sfRenderWindow_drawText(game->window, game->score.text, NULL);
    sfRenderWindow_drawText(game->window, game->high_score.text, NULL);
    sfRenderWindow_drawText(game->window, game->vie_text.text, NULL);
    free(strcat_char);
    free(game->score.text_char);
}