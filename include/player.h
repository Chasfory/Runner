/*
** EPITECH PROJECT, 2021
** player.h
** File description:
** runner
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "runner.h"

enum states {
    run,
    jump,
};

typedef struct player_s {
    sfTexture *dino;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f scale;
    int mum;
    enum states event;
} player_t;

void draw_sprite(player_t *player, sfRenderWindow *window);
void draw_parallaxe(sfSprite *sprite, sfRenderWindow *window);
player_t init_player(program_t *param);
void create_player(player_t *player);
sfMusic *music();
void event_player(player_t *player);

#endif