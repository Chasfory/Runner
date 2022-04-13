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
#include "object.h"
#include "player.h"
#include "counter.h"
#include "enemy.h"

void finish_game(sfRenderWindow *window, counter_t *score, sfEvent *event)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_game_over(window);
    draw_presse(window);
    draw_score(window, score);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_display(window);
}

void finish_game_victory(sfRenderWindow *window, counter_t *score,
sfEvent *event)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_game_victory(window);
    draw_presse(window);
    draw_score(window, score);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_display(window);
}