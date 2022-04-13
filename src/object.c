/*
** EPITECH PROJECT, 2021
** runner
** File description:
** object.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "object.h"

int object_create(object_t *object, const sfTexture *texture,
sfVector2f window_size)
{
    object->sprite = sfSprite_create();
    if (object->sprite == NULL) {
        return -1;
    }
    object->texture = texture;
    object->velocity.x = 0;
    object->velocity.y = 0;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, window_size);
    return 0;
}

void object_move(object_t *object, float dt)
{
    const sfVector2f offset = {
        .x = object->velocity.x * dt,
        .y = object->velocity.y * dt,
    };
    sfSprite_move(object->sprite, offset);
}

void object_set_rect(object_t *object, const sfIntRect *rect)
{
    sfSprite_setTextureRect(object->sprite, *rect);
}

void object_destroy(object_t *object)
{
    sfSprite_destroy(object->sprite);
}