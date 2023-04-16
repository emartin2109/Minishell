/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_unsetenv
*/

#include "include.h"
#include "lib.h"
#include "my_command.h"

static void delete_env(char *args, env_t *current_env)
{
    env_t *temp_env = NULL;
    while (current_env->next && my_strcmp(args, current_env->next->variable))
        current_env = current_env->next;
    if (current_env->next == NULL)
        return;
    temp_env = current_env->next;
    current_env->next = current_env->next->next;
    if (temp_env == NULL)
        return;
    if (temp_env->variable == NULL)
        return;
    free(temp_env->variable);
    free(temp_env);
}

void my_unsetenv (char ** args, env_t *current_env)
{
    int i = 0;
    if (args[1] == NULL) {
        write(1, "unsetenv: Too few arguments.\n", 29);
        return;
    }
    while (args[++i]) {
        args[i] = my_strcat(args[i], "=");
        delete_env(args[i], current_env);
    }
}
