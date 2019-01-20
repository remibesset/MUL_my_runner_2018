/*
** EPITECH PROJECT, 2018
** init texture sprite
** File description:
** texture sprite
*/

#include "../../includes/my.h"

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