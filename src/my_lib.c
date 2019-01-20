/*
** EPITECH PROJECT, 2018
** lib infinadd
** File description:
** lib for the infinadd
*/

#include <unistd.h>
#include <stdlib.h>
#include "../includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int max = my_strlen(str);
    int j = max - 1;
    char *rev = malloc(sizeof(char) * (my_strlen(str) + 2));

    while (i < max) {
        rev[i] = str[j];
        i++;
        j--;
    }
    rev[i] = '\0';
    str = rev;
    return (str);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((int)str[i] == 92 && (int)str[i+1] == 110)
            my_putchar(10);
        else
            my_putchar(str[i]);
        i++;
    }
}

int char_to_int(char *score)
{
    int score_int = 0;

    for (int i = 0; score[i] != '\0'; i++) {
        if (score[i] >= '0' && score[i] <= '9') {
            score_int = (score_int * 10) + (score[i] - '0');
        }
    }
    return (score_int);
}