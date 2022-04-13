/*
** EPITECH PROJECT, 2021
** object.h
** File description:
** runner
*/


#ifndef STRUCT_GLOBAL_H
#define STRUCT_GLOBAL_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "counter.h"
#include "enemy.h"
#include "object.h"
#include "player.h"
#include "runner.h"

typedef struct struct_game_s {
    object_t *parallaxe;
    sfEvent event;
    sfRenderWindow *window;
    sfVector2f window_size;
    sfClock *clock;
    sfClock *clock_game;
    player_t player;
    enemy_t enemy;
    counter_t score;
    sfMusic *music_fond;
    int tmp;
} struct_game_t;

void game_loop_infinite(struct_game_t *struct_game);
void game_event_infinite(sfRenderWindow *window, player_t *player,
sfEvent *event, sfMusic *music_fond);
int first_game_infinite(struct_game_t *struct_game, program_t *param);
int init_global_struct_infinite(struct_game_t *struct_game, program_t *param);
char *my_itoa(int nb);
int first_game(struct_game_t *struct_game, program_t *param);
void destroy_struct(struct_game_t *struct_game);
void event_pause(sfRenderWindow *window, sfEvent *event);

#endif /* !STRUCT_GAME_H */