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

void draw_sprite(player_t *player, sfRenderWindow *window)
{
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->position);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}

void draw_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
}

void draw_parallaxe(sfSprite *sprite, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

int draw_game(sfRenderWindow *window, object_t *parallaxe, player_t *player,
enemy_t *enemy)
{
    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0; i < 8; i++) {
        draw_parallaxe(parallaxe[i].sprite, window);
    }
    draw_sprite(player, window);
    if (enemy->game[enemy->tmp] == '2') {
        draw_enemy(enemy, window);
    }
    if (enemy->game[enemy->tmp] == '0') {
        return 1;
    }
    return 0;
}

void draw_counter(counter_t *score, sfRenderWindow *Window)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");

    sfText_setString(score->score_text, my_itoa(score->score));
    sfText_setFont(score->score_text, Texture);
    sfText_setScale(score->score_text, (sfVector2f){2, 2});
    sfText_setPosition(score->score_text, (sfVector2f){50, 50});
    sfRenderWindow_drawText(Window, score->score_text, NULL);
}