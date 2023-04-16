/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcmp
*/

#include "../include/my.h"
#include "lib.h"

int is_in_list (char const *list, char const c)
{
    int i = -1;
    if (list == NULL)
        return 0;
    while (list[++i]) {
        if (list[i] == c)
            return 1;
    }
    return 0;
}

int my_strcmp (char const *s1 ,char const *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    if (!s1[i] || !s2[i])
        return 0;
    return s1[i] - s2[i];
}
