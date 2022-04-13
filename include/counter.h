/*
** EPITECH PROJECT, 2021
** counter.h
** File description:
** My_runner
*/

#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct counter_s {
    sfText *score_text;
    sfText *score_finish;
    sfText *best_score_text;
    char *counter_play;
    int best_score;
    int score;
} counter_t;

void draw_counter(counter_t *score, sfRenderWindow *Window);
void finish_game(sfRenderWindow *window, counter_t *score, sfEvent *event);
void finish_game_victory(sfRenderWindow *window, counter_t *score, sfEvent *event);
void draw_score(sfRenderWindow *window, counter_t *score);
void draw_game_over(sfRenderWindow *window);
void draw_game_victory(sfRenderWindow *window);
void draw_presse(sfRenderWindow *window);
void create_counter(counter_t *score, sfRenderWindow *window);
counter_t init_struc_counter(void);

#endif