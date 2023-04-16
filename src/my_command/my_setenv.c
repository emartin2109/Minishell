/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_setenv
*/

#include "include.h"
#include "lib.h"
#include "my_command.h"
#include "utils.h"

void create_env_variable (char *env, char *value, env_t * current_env)
{
    env = my_strcat_no_free(env, value);
    char * temp = NULL;
    if (current_env != NULL) {
        while (current_env->next)
            current_env = current_env->next;
        current_env->next = malloc(sizeof(env_t));
        current_env->next->variable = malloc(my_strlen(env) + 1);
        my_strcpy(current_env->next->variable, env);
        current_env->next->next = NULL;
        return;
    }
    current_env = malloc(sizeof(env_t));
    current_env->variable = malloc(my_strlen(env) + 1);
    current_env->variable = my_strcpy(current_env->variable, env);
    current_env->next = NULL;
}

static int update_env(char ** args, env_t *current_env)
{
    env_t *temp_env = current_env;
    while (current_env) {
        if (!my_strcmp(current_env->variable, args[1])) {
            args[1] = my_strcat(args[1], args[2]);
            free(current_env->variable);
            current_env->variable = malloc(my_strlen(args[1]) + 1);
            current_env->variable = my_strcpy(current_env->variable, args[1]);
            return 1;
        }
        temp_env = current_env;
        current_env = current_env->next;
    }
    temp_env->next = malloc(sizeof(env_t));
    args[1] = my_strcat(args[1], args[2]);
    temp_env->next->variable = malloc(my_strlen(args[1]) + 1);
    temp_env->next->variable = my_strcpy(temp_env->next->variable, args[1]);
    temp_env->next->next = NULL;
    return 0;
}

static int is_args_valid(char *args)
{
    int i = -1;
    if ((args[0] < 'A' || args[0] > 'Z') && (args[0] < 'a' || args[0] > 'z')) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    if (!my_str_is_alphanum(args)) {
        write(1, "setenv: Variable name must contain", 34);
        write(1, " alphanumeric characters.\n", 26);
        return 0;
    }
    return 1;
}

void my_setenv (char ** args, env_t *current_env)
{
    if (args[1] == NULL)
        return my_env(current_env);
    if (my_str_str_len(args) > 3) {
        write(1, "setenv: Too many arguments.\n", 28);
        return;
    }
    if (!is_args_valid(args[1]))
        return;
    args[1] = my_strcat(args[1], "=");
    update_env(args, current_env);
}

void intern_setenv (char *env, char *value ,env_t *head_env)
{
    env_t *current_env = head_env;
    while (current_env) {
        if (!my_strcmp(current_env->variable, env)) {
            env = my_strcat_no_free(env, value);
            free(current_env->variable);
            current_env->variable = malloc(my_strlen(env) + 1);
            current_env->variable = my_strcpy(current_env->variable, env);
            free(env);
            return;
        }
        current_env = current_env->next;
    }
    create_env_variable(env, value, head_env);
}
