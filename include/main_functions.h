/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#include "include.h"

#ifndef MAIN_FUNCTIONS_H_
    #define MAIN_FUNCTIONS_H_

int handle_command (char **words, env_t *head_env);
int exec_pre_build_command (char **words, env_t *env);
int my_sh (int ac, char **av, env_t *head_env);

#endif /* !MAIN_FUNCTIONS_H_ */
