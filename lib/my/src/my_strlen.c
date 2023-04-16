/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strlen
*/

#include "../include/my.h"
#include "lib.h"

int my_strlen (char const *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_str_str_len (char **str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    while (str[i])
        i++;
    return i;
}
