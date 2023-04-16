/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_env
*/

#include "include.h"
#include "lib.h"

void my_env (env_t *head_env)
{
    env_t *current_env = head_env;
    while (current_env != NULL) {
        write(1, current_env->variable, my_strlen(current_env->variable));
        write(1, "\n", 1);
        current_env = current_env->next;
    }
}
