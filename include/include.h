/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** .h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <fcntl.h>
    #include <limits.h>

    #define ERROR 84
    #define SUCCESS 0
    #define FAILURE 1

typedef struct env {
    char *variable;
    struct env *next;
} env_t;

#endif /* !INCLUDE_H_ */
