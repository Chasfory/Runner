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

int funct_help(program_t *param, const char **av)
{
    (void)param;
    (void)av;
    my_putstr("Finite runner created with CSFML\n\nUSAGE\n./my_runner\n\n"
        "OPTIONS\n-i and --infinite\tlaunch the game in infinity mode"
        "\n-h and --help\t\tprint the usage and quit\n-W and --wind"
        "ow-name\tchange the window nam\n-w and --width\t\tchange "
        "the window size\n-f and --fps\t\tchange fps\n-m and --maps"
        "\t\tdefine the map\n-c and --colors\t\tuse skins"
        "\nUSER INTERACTIONS\nSPACE_KEY\tjump\n"
        "A\t\tpause the game\nESCAPE\t\trestart the game\n");
    param->mode = 2;
    return 0;
}

int funct_colors(program_t *param, const char **av)
{
    param->color = av[1];
    return 0;
}