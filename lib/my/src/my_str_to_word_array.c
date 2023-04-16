/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"
#include "lib.h"

int count_word (char const * str)
{
    int c = 1;
    int i = -1;
    int nbw = 0;

    while (++i < my_strlen(str)) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && c == 1) {
            nbw++;
            c = 0;
            continue;
        }
        if (c == 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')) {
            c = 1;
        }
    }
    return (nbw);
}

void separate_words (char const *str, char **word_l)
{
    int i = -1;
    int j = 0;
    int y = 0;
    int verif = 1;
    while (++i < my_strlen(str)) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            word_l[y][j++] = str[i];
            verif = 0;
            continue;
        }
        if (verif == 0) {
            word_l[y++][j] = '\0';
            j = 0;
            verif = 1;
        }
    }
    if (word_l[y] != NULL)
        word_l[y][j] = '\0';
}

char **my_str_to_word_array (char * str)
{
    int wd_nb = count_word(str);
    int i = -1;
    char **word_l = NULL;

    if (str == NULL)
        return NULL;
    word_l = malloc(sizeof(char*) * (wd_nb + 1));
    if (word_l == NULL)
        return NULL;
    while (++i < wd_nb) {
        word_l[i] = malloc(my_strlen(str) * sizeof(char) + 1);
        if (word_l[i] == NULL)
            return NULL;
    }
    word_l[i] = NULL;
    separate_words (str, word_l);
    free(str);
    return word_l;
}
