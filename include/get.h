/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#include "include.h"

#ifndef GET_H_
    #define GET_H_

char *get_input (void);
char *get_path (char *path_list, char *command);
char *get_env_variable(char *name, env_t *head_env);

#endif /* !GET_H_ */
