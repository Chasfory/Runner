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

void event_pause(sfRenderWindow *window, sfEvent *event)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");
    sfText *pause_game = sfText_create();
    int i = 0;

    sfText_setString(pause_game, "PAUSE");
    sfText_setFont(pause_game, Texture);
    sfText_setScale(pause_game, (sfVector2f){6, 6});
    sfText_setPosition(pause_game, (sfVector2f){650, 400});
    while (sfRenderWindow_isOpen(window) && i == 0) {
        while(sfRenderWindow_pollEvent(window, event)) {
            sfRenderWindow_drawText(window, pause_game, NULL);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
                i = 1;
            }
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
    sfText_destroy(pause_game);
}