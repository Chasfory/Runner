/*
** EPITECH PROJECT, 2021
** object.h
** File description:
** runner
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "enemy.h"

#ifndef OBJECT_H
#define OBJECT_H

typedef struct object_s {
    sfSprite *sprite;
    const sfTexture *texture;
    sfVector2f velocity;
} object_t;

void object_destroy(object_t *object);
void object_move(object_t *object, float dt);
void object_set_rect(object_t *object, const sfIntRect *rect);
int object_create(object_t *object, const sfTexture *texture, sfVector2f window_size);

int texture_create(const char *arg, object_t *object, object_t *object_bis, sfVector2f window_size);
int create_texture(const char *arg, object_t *object, object_t *object_bis, sfVector2f window_size);
void draw_parallaxe(sfSprite *sprite, sfRenderWindow *window);
void play_game(sfClock *clock, object_t *parallaxe);
void parallaxe_move(object_t *parallaxe, object_t *parallaxe_bis, sfVector2f move);
void funct_post_2_parallaxe(object_t *parallaxe);

#endif /* !OBJECT_H */