/*
** EPITECH PROJECT, 2023
** stumper02
** File description:
** main
*/

#include "main_functions.h"
#include "utils.h"

int main (int argc , char ** argv , char *const *const env)
{
    int retval = 0;
    if (argc != 1)
        return 84;
    retval = my_sh(argc, argv, transform_env_struct(env));
}
