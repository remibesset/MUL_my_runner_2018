/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include "../../includes/my.h"

text_score_t init_text_high_score(game_t *game)
{
    text_score_t text_name_game;
    int fd = open("includes/score.txt", O_RDONLY);
    char buff[256] = {'\0'};
    read(fd, buff, 256);


    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = 50;
    text_name_game.pos_text.y = game->mode.height / 2 + 310;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    text_name_game.score = char_to_int(buff);
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 20);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, my_strcat("HIGH SCORE: ", buff));
    return (text_name_game);
}

text_score_t init_text_menu_game(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 - 190;
    text_name_game.pos_text.y = 100;
    text_name_game.font = sfFont_createFromFile("includes/Ninja Rush.otf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 80);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "MENU");
    return (text_name_game);
}

text_score_t init_text_resume_text(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 - 190;
    text_name_game.pos_text.y = game->mode.height / 2 - 100;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 50);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "RESUME");
    return (text_name_game);
}

text_score_t init_text_vie(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = 50;
    text_name_game.pos_text.y = 50;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    text_name_game.score = 0;
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 30);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "LIFE: ");
    return (text_name_game);
}

text_score_t init_text_vic_def_game(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 - 230;
    text_name_game.pos_text.y = game->mode.height / 2 - 300;
    text_name_game.font = sfFont_createFromFile("includes/Ninja Rush.otf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 80);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "VICTORY");
    return (text_name_game);
}