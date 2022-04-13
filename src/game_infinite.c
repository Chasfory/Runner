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

int first_game_infinite(struct_game_t *struct_game, program_t *param)
{
    for (size_t i = 0; i < (sizeof(path_to_texture) /
    sizeof(path_to_texture[0])); i++, struct_game->tmp += 2) {
        if (create_texture(path_to_texture[i],
        &(struct_game->parallaxe[struct_game->tmp]),
        &(struct_game->parallaxe[struct_game->tmp + 1]),
        struct_game->window_size) == -1) {
            return -1;
        }
    }
    sfMusic_setVolume(struct_game->music_fond, 20);
    sfMusic_play(struct_game->music_fond);
    create_player(&struct_game->player);
    create_enemy(&struct_game->enemy);
    sfRenderWindow_setFramerateLimit(struct_game->window, param->fps);
    funct_post_2_parallaxe(struct_game->parallaxe);
    return 0;
}

int first_game(struct_game_t *struct_game, program_t *param)
{
    if (read_maps(param->map, &struct_game->enemy) == -1) {
        return -1;
    }
    for (size_t i = 0; i < (sizeof(path_to_texture) /
    sizeof(path_to_texture[0])); i++, struct_game->tmp += 2) {
        if (create_texture(path_to_texture[i],
        &(struct_game->parallaxe[struct_game->tmp]),
        &(struct_game->parallaxe[struct_game->tmp + 1]),
        struct_game->window_size) == -1) {
            return -1;
        }
    }
    sfMusic_setVolume(struct_game->music_fond, 20);
    sfMusic_play(struct_game->music_fond);
    create_player(&struct_game->player);
    create_enemy(&struct_game->enemy);
    sfRenderWindow_setFramerateLimit(struct_game->window, param->fps);
    funct_post_2_parallaxe(struct_game->parallaxe);
    return 0;
}


void game_event_infinite(sfRenderWindow *window, player_t *player,
sfEvent *event, sfMusic *music_fond)
{
    while(sfRenderWindow_pollEvent(window, event)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
            event_player(player);
        }
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        else if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
            sfMusic_pause(music_fond);
            event_pause(window, event);
            sfMusic_play(music_fond);
        }
    }
    sfRenderWindow_display(window);
}

void game_loop_infinite(struct_game_t *struct_game)
{
    if (struct_game->tmp != -1) {
        draw_game_infinite(struct_game->window, struct_game->parallaxe,
        &struct_game->player, &struct_game->enemy);
        create_counter(&struct_game->score, struct_game->window);
        play_game(struct_game->clock, struct_game->parallaxe);
        struct_game->tmp = play_player_infinite(struct_game->clock_game,
        &struct_game->player, &struct_game->enemy, &struct_game->score);
        game_event_infinite(struct_game->window, &struct_game->player,
        &struct_game->event, struct_game->music_fond);
    } else if (struct_game->tmp == -1) {
        sfMusic_stop(struct_game->music_fond);
        finish_game(struct_game->window, &struct_game->score,
        &struct_game->event);
    }
}

int game_infinite(program_t *param)
{
    struct_game_t struct_game;

    if (init_global_struct_infinite(&struct_game, param) == -1) {
        return -1;
    }
    if (first_game_infinite(&struct_game, param) == -1) {
        return -1;
    }
    struct_game.tmp = 0;
    while (sfRenderWindow_isOpen(struct_game.window)) {
        game_loop_infinite(&struct_game);
        }
    destroy_struct(&struct_game);
    return 0;
}