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

void event_player(player_t *player)
{
    if (player->event == jump) {
        return;
    }
    player->rect.left = 120;
    player->event = jump;
}