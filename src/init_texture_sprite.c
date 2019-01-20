/*
** EPITECH PROJECT, 2018
** init texture sprite
** File description:
** texture sprite
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../includes/my.h"

init_sp_tex_t init_background_sprite(void)
{
    init_sp_tex_t init_text;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
Background.png", NULL);
    init_text.sprite = sfSprite_create();
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    return (init_text);
}

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

init_sp_tex_t init_background_soleil(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
soleil.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.5;
    init_text.speed = 1;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
soleil.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_background_ville3(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
ville3.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.1;
    init_text.speed = 1;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
ville3.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_background_ville2(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
ville2.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.06;
    init_text.speed = 1;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
ville2.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_background_ville1(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
ville1.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.02;
    init_text.speed = 1;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
ville1.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_background_ville0(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
ville0.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.015;
    init_text.speed = 1;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
ville0.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_background_tree(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
tree.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.01;
    init_text.speed = 3.5;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
tree.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
    return (init_text);
}

init_sp_tex_t init_sprite_ground(void)
{
    init_sp_tex_t init_text;
    sfVector2u pos2_temp;

    init_text.clock_st = sfClock_create();
    init_text.pos = (sfVector2f) {0, 0};
    init_text.texture = sfTexture_createFromFile("includes/images/background/\
ground.png", NULL);
    init_text.sprite = sfSprite_create();
    init_text.max_sec = 0.01;
    init_text.speed = 5;
    sfSprite_setTexture(init_text.sprite, init_text.texture, sfTrue);
    sfSprite_setPosition(init_text.sprite, init_text.pos);
    init_text.texture2 = sfTexture_createFromFile("includes/images/background/\
ground.png", NULL);
    init_text.sprite2 = sfSprite_create();
    pos2_temp = sfTexture_getSize(init_text.texture2);
    init_text.pos2 = (sfVector2f) {pos2_temp.x / 2 + 250, 0};
    sfSprite_setTexture(init_text.sprite2, init_text.texture2, sfTrue);
    sfSprite_setPosition(init_text.sprite2, init_text.pos2);
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
    sfSprite_setTexture(init_perso.sprite, init_perso.texture, sfTrue);
    init_perso.rect.width = 135;
    sfSprite_setTextureRect(init_perso.sprite, init_perso.rect);
    sfSprite_setPosition(init_perso.sprite, init_perso.pos);
    return (init_perso);
}