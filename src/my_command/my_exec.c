/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_exec
*/

#include "include.h"
#include "utils.h"
#include "lib.h"

static void print_error_msg (int err_value)
{
    if (err_value == 8 || err_value == 8 + 128) {
        write (1, "Floating exception", 18);
    } else  if (err_value == 11 || err_value == 11 + 128) {
        write (1, "Segmentation fault", 18);
    } else {
        return;
    }
    if (WCOREDUMP(err_value))
        write (1, " (core dumped)", 14);
    write(1, "\n", 1);
}

int my_exec (char **words, env_t *head_env)
{
    pid_t pid;
    char *file = words[0];
    int status;
    if (access(file, F_OK) == -1)
        return 1;
    if ((pid = fork()) == - 1)
        return 2;
    if (pid == 0) {
        if (execve(file, words, transform_env_char(head_env)) == -1) {
            write(1, words[0], my_strlen(words[0]));
            write(1, ": Permission denied.\n", 21);
        }
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (status != 0)
        print_error_msg(status);
    return 2;
}
