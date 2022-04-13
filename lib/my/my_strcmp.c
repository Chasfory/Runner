/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** task
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        *s1++;
        *s2++;
    }
    return (*s1 - *s2);
}
