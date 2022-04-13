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

void draw_score(sfRenderWindow *window, counter_t *score)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");
    sfText *score_1 = sfText_create();

    sfText_setString(score_1, "Score :");
    sfText_setFont(score_1, Texture);
    sfText_setScale(score_1, (sfVector2f){2, 2});
    sfText_setPosition(score_1, (sfVector2f){790, 650});
    sfRenderWindow_drawText(window, score_1, NULL);
    sfText_setString(score->score_text, my_itoa(score->score));
    sfText_setFont(score->score_text, Texture);
    sfText_setScale(score->score_text, (sfVector2f){2, 2});
    sfText_setPosition(score->score_text, (sfVector2f){1000, 655});
    sfRenderWindow_drawText(window, score->score_text, NULL);
}

void draw_game_over(sfRenderWindow *window)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");
    sfText *game = sfText_create();

    sfText_setString(game, "Game Over");
    sfText_setFont(game, Texture);
    sfText_setScale(game, (sfVector2f){6, 6});
    sfText_setPosition(game, (sfVector2f){500, 400});
    sfRenderWindow_drawText(window, game, NULL);
}

void draw_game_victory(sfRenderWindow *window)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");
    sfText *game = sfText_create();

    sfText_setString(game, "Victory");
    sfText_setFont(game, Texture);
    sfText_setScale(game, (sfVector2f){6, 6});
    sfText_setPosition(game, (sfVector2f){500, 400});
    sfRenderWindow_drawText(window, game, NULL);
}

void draw_presse(sfRenderWindow *window)
{
    sfFont *Texture = sfFont_createFromFile("./assets/counter.ttf");
    sfText *presse = sfText_create();

    sfText_setString(presse, "press the space button to exit");
    sfText_setFont(presse, Texture);
    sfText_setScale(presse, (sfVector2f){1, 1});
    sfText_setPosition(presse, (sfVector2f){720, 750});
    sfRenderWindow_drawText(window, presse, NULL);
}

int draw_game_infinite(sfRenderWindow *window, object_t *parallaxe,
player_t *player, enemy_t *enemy)
{
    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0; i < 8; i++) {
        draw_parallaxe(parallaxe[i].sprite, window);
    }
    draw_sprite(player, window);
    draw_enemy(enemy, window);
    return 0;
}