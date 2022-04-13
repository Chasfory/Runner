
/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** runner
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "my.h"
#include "runner.h"
#include "object.h"

int funct_window_name(program_t *param, const char **av)
{
    param->window = av[1];
    return 0;
}

int funct_width(program_t *param, const char **av)
{
    int tmp = my_getnbr(av[1]);

    if (tmp >= 0) {
        param->width = tmp;
        return 0;
    }
    return -1;
}

int funct_infinite(program_t *param, const char **av)
{
    (void) av;
    param->mode = 1;
    return 0;
}

int funct_maps(program_t *param, const char **av)
{
    param->map = av[1];
    return 0;
}

int funct_fps(program_t *param, const char **av)
{
    int tmp = my_getnbr(av[1]);

    if (tmp >= 0) {
        param->fps = tmp;
        return 0;
    }
    return -1;
}