/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include "../includes/my.h"

int set_value(game_t *game, int run)
{
    game->mode = (run != 2) ? (sfVideoMode) {1280, 768, 32} : game->mode;
    game->window = (run != 2) ? sfRenderWindow_create(game->mode, "MyRunner", \
sfDefaultStyle, NULL) : game->window;
    game->menu = (run != 2) ? 1 : game->menu;
    game->song = (run != 2) ? sfMusic_createFromFile("includes/music/\
music.ogg") : game->song;
    game->win = 0;
    game->speed_increase = 0;
    game->run = run;
    game->nb_vie = (run == 0) ? 1: 3;
    game->id_obstacle = -1;
    game->slide = 0;
    game->jump = 0;
    game->map = load_file(game->filepath, game);
    if (game->map[0] == NULL) {
        my_putstr("La map est non valide ou sans obstacle.\n");
        return (84);
    }
    set_texture_sprite(game);
    draw_the_new_life(game);
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
    game->score = init_text_score(game);
    game->vie_text = init_text_vie(game);
    game->high_score = init_text_high_score(game);
    game->menu_pause = init_text_menu_game(game);
    game->bg_menu = init_background_menu_sprite();
    game->victory_defeat = init_text_vic_def_game(game);
    game->play_again = init_text_play_again_text(game);
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

void set_pos_menu_2(game_t *game)
{
    game->exit_text.pos_text.x = game->mode.width / 2 - 190;
    game->exit_text.pos_text.y = game->mode.height / 2;
    sfText_setPosition(game->exit_text.text, game->exit_text.pos_text);
}