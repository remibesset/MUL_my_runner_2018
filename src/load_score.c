/*
** EPITECH PROJECT, 2018
** Load score
** File description:
** score
*/

#include "../includes/my.h"

char *load_file_in_memo(char const *filepath, game_t *game)
{
    char *buff = xmalloc(sizeof(char) * (11 + 14 + 1));
    int fd = open(filepath, O_RDWR);
    int j = 0;

    for (int i = 0; i < 15 + 11; buff[i] = '\0', i++);
    if (game->high_score.score < game->score.score && fd != -1)
        write(fd, my_revstr(conv_i_str(game->score.score / 4)),
        my_strlen(conv_i_str(game->score.score / 4)));
    if (fd != -1) {
        read(fd, buff, 15 + 11);
        close(fd);
    }
    buff = my_strcat("HIGH SCORE: ", buff);
    return (buff);
}
