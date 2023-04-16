/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcpy
*/

#include "../include/my.h"
#include "lib.h"

char * my_strcpy (char * dest , char const *src)
{
    int len = my_strlen (src);
    int i = -1;
    while (++i < len) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
