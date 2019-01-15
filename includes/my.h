/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>

typedef struct make_clock
{
    sfClock *clock_st;
    sfTime time_st;
    float second;
} make_clock_t;

typedef struct init_sp_tex
{
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *song;
    sfVector2f pos;
    sfTexture *texture2;
    sfSprite *sprite2;
    sfVector2f pos2;
    sfClock *clock_st;
    sfTime time_st;
    float second;
    float max_sec;
    int speed;
} init_sp_tex_t;

typedef struct player_init
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock_st;
    sfTime time_st;
    sfIntRect rect;
    sfVector2f pos;
    int i;
    float second;
    float max_sec;
    int speed;
} player_init_t;

typedef struct text_score_a
{
    sfText *text;
    sfFont *font;
    sfVector2f pos_text;
    char *text_char;
    int score;
} text_score_t;

typedef struct init_all
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    int menu;
    init_sp_tex_t background;
    init_sp_tex_t background_soleil;
    init_sp_tex_t background_ville3;
    init_sp_tex_t background_ville2;
    init_sp_tex_t background_ville1;
    init_sp_tex_t background_ville0;
    init_sp_tex_t background_tree;
    init_sp_tex_t ground;
    player_init_t perso;
    text_score_t name_game;
    text_score_t play_text;
    text_score_t exit_text;
    text_score_t option_text;
    text_score_t score;
    text_score_t high_score;
}game_t;

// typedef struct init_game
// {
//     sfRenderWindow *window;
//     sfEvent event;
//     sfVideoMode mode;
//     sfIntRect rect;
//     sfVector2f position;
//     text_score_t text_s;
//     text_score_t text_highs;
//     init_sp_tex_t bg_sky;
//     init_sp_tex_t bg_stars;
//     int run;
//     int i;
//     int die;
//     float vitesse;
//     float speed_anim;
//     int health;
//     int direction;
// } game_t;

void my_putchar(char c);
int my_strlen(char const *str);
const char *my_revstr(const char *str);
int get_the_sign(char const *str);
char *my_getnbr(char const *str);
void my_putstr(char *str);
void my_putstr_i(char *str, int max);
int my_put_nbr_print(int nb);
int my_put_nbr(int nb);
void close_window(game_t game, sfEvent event);
int analyse_events(sfRenderWindow *window, game_t game);
char *conv_i_str(int nbr);
int manage_mouse_click(sfRenderWindow *window, game_t *game,
game_t game_s);
void set_value(game_t *game, int run);
void draw_all(sfRenderWindow *window, game_t *game);
void draw_menu(game_t *game);
void analyse_events_menu(game_t *game);
init_sp_tex_t init_background_sprite(void);
init_sp_tex_t init_background_soleil(void);
init_sp_tex_t init_background_ville3(void);
init_sp_tex_t init_background_ville2(void);
init_sp_tex_t init_background_ville1(void);
init_sp_tex_t init_background_ville0(void);
init_sp_tex_t init_background_tree(void);
init_sp_tex_t init_sprite_ground(void);
player_init_t init_sprite_perso(void);
text_score_t init_text_name_game(game_t *game);
text_score_t init_text_play_text(game_t *game);
text_score_t init_text_exit_text(game_t *game);
text_score_t init_text_option_text(game_t *game);
text_score_t init_text_score(game_t *game);
text_score_t init_text_high_score(game_t *);
void do_paralax(init_sp_tex_t *background, game_t *game);
void make_run_perso(game_t *game);
void set_texture_sprite(game_t *game);
void target_mouse(game_t *game);
void make_destroy(game_t game);
char *load_file_in_memo(char const *filepath, game_t *game);
void do_animation(make_clock_t *clockanim, game_t *game, int *i,
sfIntRect *rect);
void do_position(make_clock_t *clockpos, game_t *game);
void target_mouse(game_t *game);
char *my_strcpy(char *dest, char const *src, int i);
char *my_strcat(char const *a, char const *b);
void game_over(game_t *game, sfVector2f pos_defeat);
int char_to_int(char *score);
void init_music(game_t *game);
int game_mode(int);
int menu(int);
int main(int ac, char **ag);

#endif
