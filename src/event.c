/*
** EPITECH PROJECT, 2018
** event csfml
** File description:
** csfml
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"

char *conv_i_str(int nbr)
{
    char *result = malloc(sizeof(char) * (11 + 1));
    int i = 0;

    if (nbr > 0) {
        while (nbr != 0) {
            result[i++] = nbr % 10 + '0';
            nbr /= 10;
        }
    } else
        result[i++] = '0';
    result[i] = '\0';
    return (result);
}

// void close_window(game_t game, sfEvent event)
// {
//     if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
//     event.key.code == sfKeyEscape)) {
//         sfRenderWindow_close(game.window);
//         //menu();
//     }
// }

// void event_menu_defeat(game_t game)
// {
//     sfVector2i mp;

//     if (game.event.type == sfEvtMouseButtonPressed &&
//     sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
//         mp = sfMouse_getPosition((const sfWindow *)game.window);
//         if (mp.x > 372 && mp.x < 502 && mp.y > 558 && mp.y < 595) {
//             sfRenderWindow_close(game.window);
//         } else if (mp.x > 744 && mp.x < 866 && mp.y > 554 && mp.y < 593) {
//             sfRenderWindow_close(game.window);
//             //menu();
//         } else if (mp.x > 480 && mp.x < 769 && mp.y > 484 && mp.y < 538) {
//             //game_mode(1, );
//         }
//     }
// }

// int manage_mouse_click(game_t *game)
// {
//     if (game->event->type == sfEvtKeyPressed && game->event->key.code == sfKeyE) {
//         printf("coucou\n");
//     }
//     return (0);
// }

void change_font(game_t *game, char *filepath_font, int mode)
{
    sfVector2u get_size;

    sfTexture_destroy(game->perso.texture);
    if (mode == 0) {
        game->perso.rect = (sfIntRect) {0, 0, 811, 135};
        game->perso.texture = sfTexture_createFromFile(filepath_font, &game->perso.rect);
        game->perso.pos.y -= 35.0;
        game->perso.max_sec = 0.15;
    }
    else if (mode == 1 && game->slide == 1) {
        game->perso.texture = sfTexture_createFromFile(filepath_font, NULL);
        game->perso.pos.y += 35.0;
        game->perso.max_sec = 0.75;
    }
    else if (mode == 2 && game->jump == 1) {
        game->perso.rect = (sfIntRect) {0, 0, 910, 135};
        game->perso.texture = sfTexture_createFromFile(filepath_font, &game->perso.rect);
        game->perso.max_sec = 0.1;
    }
    game->perso.i = 0;
    game->perso.rect.width = 135;
    sfSprite_setTexture(game->perso.sprite, game->perso.texture, sfTrue);
    sfSprite_setPosition(game->perso.sprite, game->perso.pos);
}

void make_the_slide(game_t *game)
{
    game->perso.time_st = sfClock_getElapsedTime(game->perso.clock_st);
    game->perso.second = game->perso.time_st.microseconds / 1000000.0;
    if (game->perso.second >= game->perso.max_sec) {
        change_font(game, "includes/images/player/nin_run.png", 0);
        game->slide = 0;
    }
}

void do_the_jump_pos(game_t *game)
{
    if (game->perso.i < 3)
    {
        game->perso.pos.y -= 5.0;
        game->perso.pos.x += 0.5;
    } else if (game->perso.i > 4) {
        game->perso.pos.y += 5.0;
        game->perso.pos.x += 0.5;
    }
    sfSprite_setPosition(game->perso.sprite, game->perso.pos);
}

void make_jump_perso(game_t *game)
{
    game->perso.time_st = sfClock_getElapsedTime(game->perso.clock_st);
    game->perso.second = game->perso.time_st.microseconds / 1000000.0;
    do_the_jump_pos(game);
    if (game->perso.second >= game->perso.max_sec) {
        game->perso.rect.left = 133 * (game->perso.i)++;
        game->perso.i = (game->perso.i > 6) ? 0 : game->perso.i;
        if (game->perso.i == 0) {
            game->perso.pos.y += 25.0;
            change_font(game, "includes/images/player/nin_run.png", 0);
            game->jump = 0;
        }
        sfSprite_setTextureRect(game->perso.sprite, game->perso.rect);
        sfClock_restart(game->perso.clock_st);
    }
}

int manage_mouse_click(game_t *game)
{

    if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
    sfKeySpace && game->jump == 0 && game->slide != 1) {
        game->jump = 1;
        change_font(game, "includes/images/player/nin_jump.png", 2);
    }
    else if (game->e_menu.type == sfEvtKeyPressed && game->e_menu.key.code ==\
    sfKeyDown && game->slide == 0  && game->jump != 1) {
        game->slide = 1;
        change_font(game, "includes/images/player/nin_slide.png", 1);
    }
}

// void analyse_events(game_t *game)
// {
//     while (sfRenderWindow_pollEvent(game->window, (sfEvent *) game->event)) {
//         printf("coucou\n");
//         //manage_mouse_click(game);
//     }
// }
