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
    game->window = sfRenderWindow_create(game->mode, "MyRunner",
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
    game->play_text = init_text_play_text(game);
    game->exit_text = init_text_exit_text(game);
    game->option_text = init_text_option_text(game);
    game->score = init_text_score(game);
    game->high_score = init_text_high_score(game);
}

void set_scale(game_t *game)
{
    sfVector2f scale_bg;

    scale_bg.x = (float)(game->mode.width) / (float)(sfTexture_getSize(game->background.texture).x);
    scale_bg.y = (float)(game->mode.height) / (float)(sfTexture_getSize(game->background.texture).y);
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

void draw_with_paralax(sfRenderWindow *window, init_sp_tex_t *display, game_t *game)
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

void draw_menu(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->name_game.text, NULL);
    sfRenderWindow_drawText(game->window, game->play_text.text, NULL);
    sfRenderWindow_drawText(game->window, game->exit_text.text, NULL);
    sfRenderWindow_drawText(game->window, game->option_text.text, NULL);
}

void draw_text(game_t *game)
{
    game->score.score = game->score.score + 1;
    sfText_setString(game->score.text, my_strcat("SCORE: ",
    my_revstr(conv_i_str(game->score.score / 4))));
    //sfText_setString(game->high_score.text, my_strcat("HIGH SCORE :", buffer));
    sfRenderWindow_drawText(game->window, game->score.text, NULL);
    sfRenderWindow_drawText(game->window, game->high_score.text, NULL);
}

void draw_all(sfRenderWindow *window, game_t *game)
{
    draw_parallax(window, game);
    sfRenderWindow_drawSprite(window, game->perso.sprite, NULL);
    make_run_perso(game);
    if (game->menu == 1)
        draw_menu(game);
    else
        draw_text(game);
    sfRenderWindow_display(window);
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