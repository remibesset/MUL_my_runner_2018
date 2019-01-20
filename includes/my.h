/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
    float speed;
} init_sp_tex_t;

typedef struct player_init
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock_st;
    sfTime time_st;
    sfIntRect rect;
    sfVector2f pos;
    sfMusic *sound_hit;
    int i;
    float second;
    float max_sec;
    float speed;
} player_init_t;

typedef struct text_score_a
{
    sfText *text;
    sfFont *font;
    sfVector2f pos_text;
    char *text_char;
    int score;
} text_score_t;

typedef struct sprite_map
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_base;
    int type;
} sprite_map_t;

typedef struct init_all
{
    sfRenderWindow *window;
    sfEvent *event;
    sfEvent e_menu;
    sfVideoMode mode;
    sfMusic *song;
    int menu;
    int run;
    char *filepath;
    int nb_vie;
    int id_obstacle;
    int slide;
    int jump;
    float speed_increase;
    int win;
    sprite_map_t **map;
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
    text_score_t resume;
    text_score_t score;
    text_score_t high_score;
    text_score_t vie_text;
    init_sp_tex_t bg_menu;
    text_score_t menu_pause;
    text_score_t victory_defeat;
    text_score_t play_again;
}game_t;

void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int get_the_sign(char const *str);
char *my_getnbr(char const *str);
void my_putstr(char *str);
void my_putstr_i(char *str, int max);
int my_put_nbr_print(int nb);
int my_put_nbr(int nb);
void close_window(game_t game, sfEvent event);
void analyse_events(game_t *game);
char *conv_i_str(int nbr);
int manage_mouse_click(game_t *game);
int set_value(game_t *game, int run);
void draw_all(sfRenderWindow *window, game_t *game);
void draw_menu1(game_t *game);
void draw_menu2(game_t *game);
void draw_the_new_life(game_t *game);
void analyse_events_menu(game_t *game);
void set_scale(game_t *game);
void draw_parallax(sfRenderWindow *window, game_t *game);
int condition_manage_click_menu(game_t *game, int nbr,
sfVector2i mouse_position);
int condition_manage_click_menu2(game_t *game, int nbr,
sfVector2i mouse_position);
int condition_manage_click_vic_defeat(game_t *game, int nbr,
sfVector2i mouse_position);
void detect_colision(game_t *game, int i);
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
text_score_t init_text_resume_text(game_t *game);
text_score_t init_text_exit_text(game_t *game);
text_score_t init_text_option_text(game_t *game);
text_score_t init_text_score(game_t *game);
text_score_t init_text_high_score(game_t *);
text_score_t init_text_vie(game_t *game);
text_score_t init_text_menu_game(game_t *game);
init_sp_tex_t init_background_menu_sprite(void);
text_score_t init_text_vic_def_game(game_t *game);
text_score_t init_text_play_again_text(game_t *game);
void draw_defeat(game_t *game, int);
void manage_mouse_click_menu2(sfRenderWindow *window, game_t *game);
int my_strlen_liste(sprite_map_t **list);
int my_strlen_char(char **list);
char **my_realloc_charchar(char **list, char *name);
sprite_map_t **my_realloc_struct(sprite_map_t **list, sprite_map_t *name);
sprite_map_t *new_object(int i, int j, int num, game_t *);
sprite_map_t **load_file(char *filepath, game_t *);
sprite_map_t **complete_list(char **buff, sprite_map_t **list, game_t *);
void make_the_slide(game_t *game);
void make_jump_perso(game_t *game);
void draw_text(game_t *game);
void set_pos_menu_2(game_t *game);
void init_first_change_font(game_t *game, char *filepath_font, int mode);

void do_paralax(init_sp_tex_t *background, game_t *game);
void make_run_perso(game_t *game);
void set_texture_sprite(game_t *game);
void make_destroy(game_t game);
char *load_file_in_memo(char const *filepath, game_t *game);
char *my_strcpy(char *dest, char const *src, int i);
char *my_strcat(char const *a, char const *b);
int char_to_int(char *score);
void init_music(game_t *game);
int game_mode(int, char *);
int menu(int);
int main(int ac, char **ag);

#endif
