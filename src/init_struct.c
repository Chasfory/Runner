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

player_t init_player(program_t *param)
{
    player_t player;

    player.dino = sfTexture_createFromFile
        (param->color, NULL);
    player.sprite = sfSprite_create();
    player.rect.width = 24;
    player.rect.height = 24;
    player.mum = 0;
    player.rect.top = 0;
    player.rect.left = 48;
    player.position.x = 200;
    player.position.y = 800;
    player.scale.x = 8.0;
    player.scale.y = 8.0;
    player.event = run;
    return player;
}

counter_t init_struc_counter(void)
{
    counter_t score;

    score.score_text = sfText_create();
    score.counter_play = NULL;
    score.best_score_text = sfText_create();
    score.best_score = 0;
    score.score = 0;
    return score;
}

enemy_t init_enemy(void)
{
    enemy_t enemy;

    enemy.enemy = sfTexture_createFromFile("./assets/Happy/Attack.png", NULL);
    enemy.sprite = sfSprite_create();
    enemy.rect.width = 27;
    enemy.rect.height = 17;
    enemy.rect.left = 108;
    enemy.rect.top = 0;
    enemy.position.x = 2020;
    enemy.position.y = 880;
    enemy.scale.y = 5.0;
    enemy.scale.x = 5.0;
    enemy.compt_enemy = 0;
    enemy.tmp = 0;
    return enemy;
}