/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include "../../includes/my.h"

text_score_t init_text_play_again_text(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 - 300;
    text_name_game.pos_text.y = game->mode.height / 2;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 50);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "PLAY AGAIN");
    return (text_name_game);
}