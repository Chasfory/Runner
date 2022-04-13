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

int read_maps(const char *maps, enemy_t *enemy)
{
    size_t n = 0;
    FILE *f = fopen(maps, "r");
    ssize_t tmp = getline(&enemy->game, &n, f);

    if (tmp == -1) {
        return -1;
    }
    fclose(f);
    return 0;
}