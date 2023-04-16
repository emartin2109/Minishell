/*
** EPITECH PROJECT, 2023
** .type_repo
** File description:
** utils
*/

#include "include.h"
#include "lib.h"

int my_str_is_alphanum (char *str)
{
    int i = -1;
    int nb_of_valid_if = 0;
    if (str == NULL)
        return 0;
    while (str[++i]) {
        nb_of_valid_if = 0;
        if (str[i] < 'a' || str[i] > 'z')
            nb_of_valid_if++;
        if (str[i] < 'A' || str[i] > 'Z')
            nb_of_valid_if++;
        if (str[i] < '0' || str[i] > '9')
            nb_of_valid_if++;
        if (nb_of_valid_if == 3)
            return 0;
    }
    return 1;
}

env_t *transform_env_struct (char *const *const env)
{
    env_t *head_env = malloc(sizeof(env_t));
    if (head_env == NULL)
        return NULL;
    int i = 0;
    head_env->variable = malloc(my_strlen(env[0]) + 1);
    if (head_env->variable == NULL)
        return NULL;
    my_strcpy(head_env->variable, env[0]);
    head_env->next = NULL;
    env_t *current = head_env;
    while (env[++i]) {
        current->next = malloc(sizeof(env_t));
        current->next->variable = malloc(my_strlen(env[i]) + 1);
        my_strcpy(current->next->variable, env[i]);
        current->next->next = NULL;
        current = current->next;
    }
    return head_env;
}

char **transform_env_char (env_t *head_env)
{
    env_t *current_env = head_env;
    int i = 0;
    while (current_env) {
        i++;
        current_env = current_env->next;
    }
    current_env = head_env;
    char **env = malloc((i + 1) * sizeof(char *));
    if (env == NULL)
        return NULL;
    i = 0;
    while (current_env) {
        env[i++] = current_env->variable;
        current_env = current_env->next;
    }
    env[i] = NULL;
    return env;
}

void my_free_str_str (char **data)
{
    int i = -1;
    if (data == NULL)
        return;
    while (data[++i])
        free(data[i]);
    free(data);
}

void my_free_env_t (env_t *current_env)
{
    while (current_env) {
        env_t *temp_env = current_env;
        free(current_env->variable);
        current_env = current_env->next;
        free(temp_env);
    }
}
