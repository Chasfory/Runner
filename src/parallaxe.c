/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** runner
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "my.h"
#include "struct_global.h"

void parallaxe_move(object_t *parallaxe, object_t *parallaxe_bis,
sfVector2f move)
{
    sfVector2f post = sfSprite_getPosition(parallaxe->sprite);
    sfVector2f post_bis = sfSprite_getPosition(parallaxe_bis->sprite);

    if (post.x <= -1920 || post_bis.x <= -20) {
        sfSprite_setPosition(parallaxe->sprite, (sfVector2f){0, 0});
        sfSprite_setPosition(parallaxe_bis->sprite, (sfVector2f){1920, 0});
    } else {
        sfSprite_move(parallaxe->sprite, move);
        sfSprite_move(parallaxe_bis->sprite, move);
    }
}

void play_game(sfClock *clock, object_t *parallaxe)
{
    sfTime time;
    float seconds;
    sfVector2f move = {-1.0, 0.0};

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / (10000.0);
    if (seconds > 1.0) {
        for (int i = 0; i < 8; i += 2) {
            parallaxe_move(&parallaxe[i], &parallaxe[i + 1], move);
            move.x += -1.0;
        }
        move.x = -2.0;
        sfClock_restart(clock);
    }
}

void funct_post_2_parallaxe(object_t *parallaxe)
{
    sfVector2f post_2_parallaxe = {1920, 0};

    for (int i = 1; i < 8; i += 2) {
        sfSprite_setPosition(parallaxe[i].sprite, post_2_parallaxe);
    }
}