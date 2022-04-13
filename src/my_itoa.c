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
#include "object.h"
#include "player.h"
#include "counter.h"
#include "enemy.h"

char *my_itoa_bis(int nb, int cmp, int nega)
{
    int mod = 0;
    char *str;

    str = malloc(sizeof(char) * (cmp + nega + 1));
    if (str == NULL) {
        return NULL;
    }
    if (nega == 1)
        str[0] = '-';
    for (int i = nega; i < cmp; i++) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = ((nb - mod) / 10);
            str[i] = ('0' + mod);
        }
        else
            str[i] = '0' + (nb % 10);
    }
    str[cmp] = '\0';
    return (str);
}

char *my_itoa(int nb)
{
    char *str;
    int nega = 0;
    int cmp = 0;

    nega = (nb < 0) ? 1: 0;
    nb *= (nb < 0) ? -1: 1;
    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        if (str == NULL) {
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (int compt = nb; compt > 0; compt /= 10) {
        cmp += 1;
    }
    str = my_itoa_bis(nb, cmp, nega);
    my_revstr(str);
    return (str);
}