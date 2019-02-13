/*
** EPITECH PROJECT, 2018
** My Runner project
** File description:
** My runner Main
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"
#include <SFML/Audio.h>

int main(int ac, char **ag)
{
    if (ac == 2 && ag[1][0] == '-' && ag[1][1] == 'h') {
        my_putstr("prinFinite runner created with CSFML.\n\n");
        my_putstr("USAGE\n");
        my_putstr("\t./my_runner map/map.txt\n\n\n");
        my_putstr("OPTIONS\n");
        my_putstr("\t-i \t\t\tlaunch the game in infinity mode.\n");
        my_putstr("\t-h \t\t\tprint the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr("\tSPACE_KEY \tjump.\n\tDOWN_KEY \tSLIDE.\n\tQ_KEY\t\
        Quit.\n");
    } else if (ac == 2 && ag[1][0] == '-' && ag[1][1] == 'i') {
        game_mode(0, "\0");
    }
    if (ac == 2 && ag[1][0] != '-') {
        if (game_mode(1, ag[1]) == 84)
            return (84);
    } else {
        return (84);
    }
    return (0);
}