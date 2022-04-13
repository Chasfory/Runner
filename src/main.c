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

bool is_valid_opt(opt_t const *opt, char const *arg, int ac)
{
    if (my_strcmp(opt->opt, arg) == 0 || my_strcmp(opt->optlong, arg) == 0) {
        if (opt->argument_required == true && ac == 1)
            return false;
        return true;
    }
    return false;
}

int check_funct(program_t *param, char const **av, int ac)
{
    for (size_t i = 0; i < (sizeof(PROGRAM_HANDLER) /
    sizeof(PROGRAM_HANDLER[0])); i++) {
        if (is_valid_opt(&PROGRAM_HANDLER[i], av[0], ac) == true)
            return PROGRAM_HANDLER[i].handler(param, av);
    }
    return -1;
}

int direction_funct(program_t *param, char const **av, int ac)
{
    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-') {
            if (check_funct(param, &av[i], ac - i) == -1)
                return -1;
        }
    }
    return 0;
}

int main(int ac, const char **av)
{
    program_t param = {
        .width = 1920,
        .height = 1080,
        .fps = 60,
        .window = "my_runner",
        .map = "./map/map1",
        .mode = 0,
        .color = "./assets/dino/sheets/doux.png",
    };

    if (direction_funct(&param, av, ac) == -1)
        return 84;
    if (param.mode == 2)
        return 0;
    if (param.mode == 0) {
        if (game(&param) == -1)
            return 84;
    } else {
        if (game_infinite(&param) == -1)
            return 84;
    }
    return 0;
}