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

int create_texture(const char *arg, object_t *object, object_t *object_bis, sfVector2f window_size)
{
    sfTexture *texture = sfTexture_createFromFile(arg, NULL);
    if (texture == NULL) {
        return -1;
    }
    if (object_create(object, texture, window_size) == -1) {
        return -1;
    } else if (object_create(object_bis, texture, window_size) == -1) {
        return -1;
    }
    return 0;
}

sfRenderWindow *create_window(program_t *param)
{
    sfVideoMode video_mode = {param->width, param->height, param->fps};
    return (sfRenderWindow_create(video_mode, param->window, sfDefaultStyle, NULL));
}

void create_counter(counter_t *score, sfRenderWindow *window)
{
    draw_counter(score, window);
}

void create_player(player_t *player)
{
    sfSprite_setScale(player->sprite, player->scale);
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTexture(player->sprite, player->dino, sfFalse);
}

void create_enemy(enemy_t *enemy)
{
    sfSprite_setScale(enemy->sprite, enemy->scale);
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfSprite_setTexture(enemy->sprite, enemy->enemy, sfFalse);
}