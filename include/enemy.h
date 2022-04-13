/*
** EPITECH PROJECT, 2021
** object.h
** File description:
** runner
*/

#include <SFML/Graphics.h>


#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "object.h"
#include "counter.h"

typedef struct enemy_s {
    sfTexture *enemy;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f scale;
    char *game;
    int compt_enemy;
    int tmp;
} enemy_t;

void draw_enemy(enemy_t *enemy, sfRenderWindow *window);
void create_enemy(enemy_t *enemy);
int parallaxe_create(sfRenderWindow *window, object_t *parallaxe, player_t *player, enemy_t *enemy);
int draw_game(sfRenderWindow *window, object_t *parallaxe, player_t *player, enemy_t *enemy);
int draw_game_infinite(sfRenderWindow *window, object_t *parallaxe,
player_t *player, enemy_t *enemy);
enemy_t init_enemy(void);
int read_maps(const char *maps, enemy_t *enemy);
int play_player(sfClock *clock_game, player_t *player, enemy_t *enemy, counter_t *score);
int play_player_infinite(sfClock *clock_game, player_t *player, enemy_t *enemy, counter_t *score);

#endif /* !ENEMY_H */