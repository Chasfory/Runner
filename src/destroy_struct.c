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

void destroy_struct(struct_game_t *struct_game)
{
    sfTexture_destroy(struct_game->player.dino);
    sfSprite_destroy(struct_game->player.sprite);
    sfSprite_destroy(struct_game->enemy.sprite);
    sfTexture_destroy(struct_game->enemy.enemy);
    sfText_destroy(struct_game->score.score_text);
    sfClock_destroy(struct_game->clock);
    sfClock_destroy(struct_game->clock_game);
    sfMusic_destroy(struct_game->music_fond);
    free(struct_game->parallaxe);
}