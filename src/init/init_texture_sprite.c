/*
** EPITECH PROJECT, 2018
** init texture sprite
** File description:
** texture sprite
*/

#include "../../includes/my.h"

init_sp_tex_t init_background_menu_sprite(void)
{
    init_sp_tex_t init_text;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/menu/\
bg_G.png", NULL);
    init_text.sprite = sfSprite_create();
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    return (init_text);
}

player_init_t init_sprite_perso(void)
{
    player_init_t init_perso;
    sfVector2u pos2_temp;

    init_perso.clock_st = sfClock_create();
    init_perso.rect = (sfIntRect) {0, 0, 811, 135};
    init_perso.texture = sfTexture_createFromFile("includes/images/player/\
nin_run.png", &init_perso.rect);
    init_perso.sprite = sfSprite_create();
    init_perso.pos = (sfVector2f) {100, 475};
    init_perso.max_sec = 0.15;
    init_perso.i = 0;
    init_perso.sound_hit = sfMusic_createFromFile("includes/music/cri.ogg");
    sfSprite_setTexture(init_perso.sprite, init_perso.texture, sfTrue);
    init_perso.rect.width = 135;
    sfSprite_setTextureRect(init_perso.sprite, init_perso.rect);
    sfSprite_setPosition(init_perso.sprite, init_perso.pos);
    return (init_perso);
}

void init_first_change_font(game_t *game, char *filepath_font, int mode)
{
    if (mode == 0) {
        game->perso.rect = (sfIntRect) {0, 0, 811, 135};
        game->perso.texture = sfTexture_createFromFile(filepath_font, \
        &game->perso.rect);
        game->perso.rect.width = 135;
        game->perso.pos.y -= 35.0;
        game->perso.max_sec = 0.15;
    }
    if (mode == 1 && game->slide == 1) {
        game->perso.texture = sfTexture_createFromFile(filepath_font, NULL);
        game->perso.pos.y += 35.0;
        game->perso.max_sec = 0.75;
    }
}