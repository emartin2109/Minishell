/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** handle_input
*/

#include "include.h"
#include "lib.h"
#include "my_command.h"
#include "get.h"
#include "utils.h"

int handle_env_command (char **words, env_t *head_env)
{
    if (my_strlen(words[0]) == 3 && !my_strcmp(words[0], "env")) {
        my_env(head_env);
        return 2;
    }
    if (my_strlen(words[0]) == 6 && !my_strcmp(words[0], "setenv")) {
        my_setenv(words, head_env);
        return 2;
    }
    if (my_strlen(words[0]) == 8 && !my_strcmp(words[0], "unsetenv")) {
        my_unsetenv(words, head_env);
        return 2;
    }
    if (is_in_list(words[0], '/'))
        return my_exec(words, head_env);
    return 1;
}

int handle_command (char **words, env_t *head_env)
{
    if (my_strlen(words[0]) == 2 && !my_strcmp(words[0], "cd")) {
        my_cd(words, head_env);
        return 2;
    }
    if (my_strlen(words[0]) == 4 && !my_strcmp(words[0], "exit")) {
        write (1, "exit\n", 5);
        return 0;
    }
    return handle_env_command(words, head_env);
}

int exec_pre_build_command (char **words, env_t *head_env)
{
    pid_t pid;
    char *path = NULL;
    int status;
    path = get_path(get_env_variable("PATH=", head_env), words[0]);
    if (path == NULL) {
        write(1, words[0], my_strlen(words[0]));
        write(1, ": Command not found.\n", 21);
        return 1;
    }
    if ((pid = fork()) == - 1)
        return -1;
    if (pid == 0)
        exit(execve(path, words, transform_env_char(head_env)));
    free(path);
    if (waitpid(pid, &status, 0) == -1)
        return -1;
    return 1;
}
