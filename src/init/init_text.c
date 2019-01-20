/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include "../../includes/my.h"

text_score_t init_text_name_game(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = 50;
    text_name_game.pos_text.y = 30;
    text_name_game.font = sfFont_createFromFile("includes/Ninja Rush.otf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 80);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "NINJA RUNNER");
    return (text_name_game);
}

text_score_t init_text_play_text(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 + 200;
    text_name_game.pos_text.y = game->mode.height / 2 - 200;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 50);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "PLAY");
    return (text_name_game);
}

text_score_t init_text_exit_text(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 + 190;
    text_name_game.pos_text.y = game->mode.height / 2 - 100;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 50);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "EXIT");
    return (text_name_game);
}

text_score_t init_text_score(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = 50;
    text_name_game.pos_text.y = game->mode.height / 2 + 250;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    text_name_game.score = 0;
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 30);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "SCORE: ");
    return (text_name_game);
}