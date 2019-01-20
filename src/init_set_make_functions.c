/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"

void set_texture_sprite(game_t *game);

void set_value(game_t *game, int run)
{
    game->mode = (sfVideoMode) {1280, 768, 32};
    game->menu = 1;
    game->nb_vie = 3;
    game->id_obstacle = -1;
    game->slide = 0;
    game->jump = 0;
    game->map = load_file(game->filepath, game);
    game->window = sfRenderWindow_create(game->mode, "MyRunner", \
    sfDefaultStyle, NULL);
    set_texture_sprite(game);
}

void set_texture_sprite(game_t *game)
{
    game->background = init_background_sprite();
    game->background_soleil = init_background_soleil();
    game->background_ville3 = init_background_ville3();
    game->background_ville2 = init_background_ville2();
    game->background_ville1 = init_background_ville1();
    game->background_ville0 = init_background_ville0();
    game->background_tree = init_background_tree();
    game->ground = init_sprite_ground();
    game->perso = init_sprite_perso();
    game->name_game = init_text_name_game(game);
    game->resume = init_text_resume_text(game);
    game->play_text = init_text_play_text(game);
    game->exit_text = init_text_exit_text(game);
    game->option_text = init_text_option_text(game);
    game->score = init_text_score(game);
    game->vie_text = init_text_vie(game);
    game->high_score = init_text_high_score(game);
    game->menu_pause = init_text_menu_game(game);
    game->bg_menu = init_background_menu_sprite();
    draw_the_new_life(game);
}

void set_scale(game_t *game)
{
    sfVector2f scale_bg;

    scale_bg.x = (float)(game->mode.width) /\
    (float)(sfTexture_getSize(game->background.texture).x);
    scale_bg.y = (float)(game->mode.height) /\
    (float)(sfTexture_getSize(game->background.texture).y);
    sfSprite_setScale(game->background.sprite, scale_bg);
    sfSprite_setScale(game->background_soleil.sprite, scale_bg);
    sfSprite_setScale(game->background_soleil.sprite2, scale_bg);
    sfSprite_setScale(game->background_ville3.sprite, scale_bg);
    sfSprite_setScale(game->background_ville3.sprite2, scale_bg);
    sfSprite_setScale(game->background_ville2.sprite, scale_bg);
    sfSprite_setScale(game->background_ville2.sprite2, scale_bg);
    sfSprite_setScale(game->background_ville1.sprite, scale_bg);
    sfSprite_setScale(game->background_ville1.sprite2, scale_bg);
    sfSprite_setScale(game->background_ville0.sprite, scale_bg);
    sfSprite_setScale(game->background_ville0.sprite2, scale_bg);
    sfSprite_setScale(game->background_tree.sprite, scale_bg);
    sfSprite_setScale(game->background_tree.sprite2, scale_bg);
    sfSprite_setScale(game->ground.sprite, scale_bg);
    sfSprite_setScale(game->ground.sprite2, scale_bg);
}

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
    sfRenderWindow_drawText(game->window, game->option_text.text, NULL);
}

void draw_menu2(game_t *game)
{
    //sfRenderWindow_drawSprite(game->window, game->bg_menu.sprite, NULL);
    sfRenderWindow_drawText(game->window, game->menu_pause.text, NULL);
    sfRenderWindow_drawText(game->window, game->resume.text, NULL);
    sfRenderWindow_drawText(game->window, game->option_text.text, NULL);
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

void draw_the_new_life(game_t *game)
{
    char *score_to_char = conv_i_str(game->nb_vie);
    char *strcat_char = my_strcat("VIE: ", score_to_char);
    sfText_setString(game->vie_text.text, strcat_char);
    free(strcat_char);
    free(score_to_char);
}

void detect_colision(game_t *game, int i)
{
    sfVector2f pos_perso = sfSprite_getPosition(game->perso.sprite);
    sfVector2u size_perso = sfTexture_getSize(game->perso.texture);
    sfVector2f pos_obstacle = game->map[i]->pos;
    sfVector2u size_obstacle = sfTexture_getSize(game->map[i]->texture);

    if (pos_obstacle.x >= pos_perso.x && pos_obstacle.x <= pos_perso.x + \
    game->perso.rect.width / 2 && pos_perso.y <= pos_obstacle.y + size_obstacle.y
    && pos_perso.y + size_perso.y >= pos_obstacle.y)
    {
        if (game->id_obstacle != i) {
            game->id_obstacle = i;
            game->nb_vie -= 1;
            draw_the_new_life(game);
        }
    }
}

void draw_map(game_t *game)
{
    int i = 0;
    float nb = (float) game->mode.width / 2;

    for (i; game->map[i] != NULL; i++) {
        game->map[i]->pos.x -= 2.5;
        detect_colision(game, i);
        sfSprite_setPosition(game->map[i]->sprite, game->map[i]->pos);
        sfRenderWindow_drawSprite(game->window, game->map[i]->sprite, NULL);
    }
    i--;
    for (int j = 0; game->map[j] != NULL; j++)
    {
        if (game->map[i]->pos.x < -nb) {
            game->map[j]->pos.x = game->map[j]->pos_base.x;
        }
    }
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
    if (game->menu == 1)
        draw_menu1(game);
    else {
        draw_map(game);
        draw_text(game);
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
    sfSprite_destroy(game.ground.sprite);
    sfSprite_destroy(game.perso.sprite);
    sfText_destroy(game.name_game.text);
    sfText_destroy(game.play_text.text);
    sfText_destroy(game.exit_text.text);
    sfText_destroy(game.option_text.text);
    sfText_destroy(game.score.text);
    sfRenderWindow_destroy(game.window);
}