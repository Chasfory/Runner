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

static const size_t MAX_PARALLAXES = 9;

void game_event(sfRenderWindow *window, player_t *player, sfEvent *event, sfMusic *music_fond)
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

int init_global_struct_infinite(struct_game_t *struct_game, program_t *param)
{
    struct_game->window_size.x = (param->width / 450);
    struct_game->window_size.y = (param->height / 265);
    struct_game->window = create_window(param);
    struct_game->tmp = 0;
    struct_game->music_fond = music();
    struct_game->score = init_struc_counter();
    struct_game->enemy = init_enemy();
    struct_game->player = init_player(param);
    struct_game->clock_game = sfClock_create();
    struct_game->clock = sfClock_create();
    struct_game->parallaxe = malloc(sizeof(object_t) * MAX_PARALLAXES);

    if (struct_game->parallaxe == NULL) {
        return -1;
    }
    return 0;
}

int init_global_struct(struct_game_t *struct_game, program_t *param)
{
    struct_game->window_size.x = (param->width / 450);
    struct_game->window_size.y = (param->height / 265);
    struct_game->window = create_window(param);
    struct_game->tmp = 0;
    struct_game->music_fond = music();
    struct_game->score = init_struc_counter();
    struct_game->enemy = init_enemy();
    struct_game->player = init_player(param);
    struct_game->clock_game = sfClock_create();
    struct_game->clock = sfClock_create();
    struct_game->parallaxe = malloc(sizeof(object_t) * MAX_PARALLAXES);
    struct_game->enemy.game = NULL;

    if (struct_game->parallaxe == NULL) {
        return -1;
    }
    return 0;
}

void game_loop(struct_game_t *struct_game)
{
    if (struct_game->tmp != -1 && struct_game->tmp != 1) {
        struct_game->tmp = draw_game(struct_game->window,
        struct_game->parallaxe, &struct_game->player, &struct_game->enemy);
        create_counter(&struct_game->score, struct_game->window);
        play_game(struct_game->clock, struct_game->parallaxe);
        struct_game->tmp = play_player(struct_game->clock_game,
        &struct_game->player, &struct_game->enemy, &struct_game->score);
        game_event(struct_game->window, &struct_game->player,
        &struct_game->event, struct_game->music_fond);
    } else if (struct_game->tmp == -1) {
        sfMusic_stop(struct_game->music_fond);
        finish_game(struct_game->window, &struct_game->score,
        &struct_game->event);
    } else {
        sfMusic_stop(struct_game->music_fond);
        finish_game_victory(struct_game->window, &struct_game->score,
        &struct_game->event);
    }
}

int game(program_t *param)
{
    struct_game_t struct_game;

    if (init_global_struct(&struct_game, param) == -1) {
        return -1;
    }
    if (first_game(&struct_game, param) == -1) {
        return -1;
    }
    struct_game.tmp = 0;
    while (sfRenderWindow_isOpen(struct_game.window)) {
        game_loop(&struct_game);
    }
    destroy_struct(&struct_game);
    return 0;
}