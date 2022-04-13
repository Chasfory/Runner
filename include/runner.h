/*
** EPITECH PROJECT, 2021
** object.h
** File description:
** runner
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef RUNNER_H
#define RUNNER_H

typedef struct program_s {
    int width;
    int height;
    int fps;
    const char *window;
    int mode;
    const char *map;
    const char *color;
} program_t;

typedef struct opt_s {
    const char *opt;
    const char *optlong;
    int (*handler)(program_t *param, const char **av);
    bool argument_required;
} opt_t;

int funct_help(program_t *param, const char **av);
int funct_window_name(program_t *param, const char **av);
int funct_width(program_t *param, const char **av);
int funct_fps(program_t *param, const char **av);
int check_funct(program_t *param, char const **av, int ac);
int direction_funct(program_t *param, char const **av, int ac);
int funct_infinite(program_t *param, const char **av);
int funct_maps(program_t *param, const char **av);
int funct_colors(program_t *param, const char **av);
int game(program_t *param);
int game_infinite(program_t *param);
bool is_valid_opt(opt_t const *opt, char const *arg, int ac);
sfRenderWindow *create_window(program_t *param);

static const opt_t PROGRAM_HANDLER[] = {
    {
        .opt = "-h",
        .optlong = "--help",
        .handler = &funct_help,
        .argument_required = false,
    },
    {
        .opt = "-W",
        .optlong = "--window-name",
        .handler = &funct_window_name,
        .argument_required = true,
    },
    {
        .opt = "-w",
        .optlong = "--width",
        .handler = &funct_width,
        .argument_required = true,
    },
    {
        .opt = "-f",
        .optlong = "--fps",
        .handler = &funct_fps,
        .argument_required = true,
    },
    {
        .opt = "-i",
        .optlong = "--infinite",
        .handler = &funct_infinite,
        .argument_required = false,
    },
    {
        .opt = "-m",
        .optlong = "--maps",
        .handler = &funct_maps,
        .argument_required = true,
    },
    {
        .opt = "-c",
        .optlong = "--colors",
        .handler = &funct_colors,
        .argument_required = true,
    }
};

static const char *path_to_texture[] = {
    "./assets/parallax/layer3.png",
    "./assets/parallax/layer2.png",
    "./assets/parallax/layer1.png",
    "./assets/parallax/layer0.png",
};

#endif /* !RUNNER_H */