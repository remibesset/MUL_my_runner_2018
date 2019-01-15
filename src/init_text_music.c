/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "../includes/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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

text_score_t init_text_option_text(game_t *game)
{
    text_score_t text_name_game;

    text_name_game.text = sfText_create();
    text_name_game.pos_text.x = game->mode.width / 2 + 180;
    text_name_game.pos_text.y = game->mode.height / 2;
    text_name_game.font = sfFont_createFromFile("includes/Fast Forward.ttf");
    sfText_setFont(text_name_game.text, text_name_game.font);
    sfText_setCharacterSize(text_name_game.text, 50);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, "OPTION");
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
    sfText_setCharacterSize(text_name_game.text, 30);
    sfText_setPosition(text_name_game.text, text_name_game.pos_text);
    sfText_setString(text_name_game.text, my_strcat("HIGH SCORE: ", buff));
    //load_file_in_memo("includes/score.txt", game)
    return (text_name_game);
}

void init_music(game_t *game)
{
    // game->bird.song = sfMusic_createFromFile("include/song/duck.ogg");
    // game->target.song = sfMusic_createFromFile("include/song/tire.ogg");
    // game->heart.song = sfMusic_createFromFile("include/song/cri.ogg");
    // game->img_menu.song = sfMusic_createFromFile("include/song/music_lch.ogg");
}