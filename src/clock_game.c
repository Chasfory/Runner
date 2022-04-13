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

void player_clock_jump(player_t *player, float dt)
{
    if (player->rect.left < 216) {
        player->position.y -= dt * dt;
        player->mum += 1;
        dt += 10;
        if (player->mum == 2 || player->mum == 4 || player->mum == 6 ||
        player->mum == 8 || player->mum == 10 || player->mum == 12) {
            player->rect.left += 24;
        }
    }
    if (player->rect.left >= 216) {
        player->position.y += 50;
        player->mum += 1;
        if (player->mum == 13 || player->mum == 15 || player->mum == 17) {
            player->rect.left += 24;
        }
    }
}

void player_clock(player_t *player)
{
    float dt = 8;

    if (player->event == run) {
            if (player->rect.left >= 168) {
                player->rect.left = 0;
            }
            player->rect.left += 24;
    }
    else if (player->event == jump) {
        if (player->rect.left >= 288) {
                player->rect.left = 0;
                player->position.y = 850;
                player->event = run;
                player->mum = 0;
            }
        player_clock_jump(player, dt);
    }
}

void enemy_clock_bis(enemy_t *enemy)
{
    if (enemy->game[enemy->tmp] == ' ') {
        if (enemy->compt_enemy == 1) {
            enemy->compt_enemy = 0;
            enemy->tmp +=1;
        }
        enemy->compt_enemy += 1;
    }
}

int enemy_clock(enemy_t *enemy)
{
    if (enemy->position.x >= -80) {
            if (enemy->rect.left == 0) {
                enemy->rect.left = 108;
            }
            enemy->rect.left -= 27;
            enemy->position.x -= 35;
        }
        else if (enemy->position.x <= -50) {
            enemy->position.x = 2020;
            enemy->tmp += 1;
        }
        enemy_clock_bis(enemy);
        if (enemy->game[enemy->tmp] == '0')
            return 1;
    return 0;
}

int play_player(sfClock *clock_game, player_t *player, enemy_t *enemy,
counter_t *score)
{
    sfTime time = sfClock_getElapsedTime(clock_game);
    float seconds = time.microseconds / (100000.0);
    sfFloatRect player_post = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect enemy_post = sfSprite_getGlobalBounds(enemy->sprite);
    player_post.width -= 30;
    enemy_post.width -= 30;
    sfBool inter = sfFloatRect_intersects(&player_post, &enemy_post, NULL);

    if (seconds > 1.0) {
        player_clock(player);
        if (enemy_clock(enemy) == 1)
            return 1;
        if (inter == 1) {
            return -1;
        }
        score->score += 1;
        sfClock_restart(clock_game);
    }
    return 0;
}