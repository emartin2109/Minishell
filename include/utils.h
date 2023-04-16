/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#include "include.h"

#ifndef UTILS_H_
    #define UTILS_H_

env_t *transform_env_struct (char *const *const env);
char **transform_env_char (env_t *head_env);
void my_free_str_str (char **data);
void my_free_env_t (env_t *current_env);
int my_str_is_alphanum (char *str);

#endif /* !UTILS_H_ */
