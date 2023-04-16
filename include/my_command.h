/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#include "include.h"

#ifndef MY_COMMAND_H_
    #define MY_COMMAND_H_

void my_cd (char ** args, env_t *head_env);
void my_env (env_t *head_env);
void my_setenv (char ** args, env_t *current_env);
void my_unsetenv (char ** args, env_t *current_env);
int my_exec (char **words, env_t *head_env);
void intern_setenv (char *env, char *value ,env_t *current_env);
void create_env_variable (char *env, char *value, env_t * current_env);

#endif /* !MY_COMMAND_H_ */
