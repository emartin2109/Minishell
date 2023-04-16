/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcat
*/

#include "../include/my.h"
#include "lib.h"

char *my_strcat_no_free (char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int add_len = my_strlen(src);
    int i = -1;
    char *result = malloc((dest_len + add_len + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    if (src == NULL) {
        free(result);
        return dest;
    }
    while (dest && dest[++i]) {
        result[i] = dest[i];
    }
    i = -1;
    while (src && src[++i])
        result[dest_len + i] = src[i];
    result[dest_len + i] = '\0';
    return result;
}

char *my_strcat (char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int add_len = my_strlen(src);
    int i = -1;
    char *result = malloc((dest_len + add_len + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    if (src == NULL) {
        free(result);
        return dest;
    }
    while (dest && dest[++i]) {
        result[i] = dest[i];
    }
    i = -1;
    while (src && src[++i])
        result[dest_len + i] = src[i];
    result[dest_len + i] = '\0';
    if (dest != NULL)
        free(dest);
    return result;
}
