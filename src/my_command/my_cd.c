/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_cd
*/

#include "include.h"
#include "get.h"
#include "lib.h"
#include "my_command.h"

static int is_a_dir (const char *path)
{
    struct stat s;
    stat(path, &s);
    return S_ISREG(s.st_mode);
}

static void set_pwd (char *dir, char temp[256], env_t *head_env)
{
    if (dir == NULL || access(dir, F_OK) == -1) {
        write(1, dir, my_strlen(dir));
        write(1, ": No such file or directory.\n", 29);
        return;
    }
    if (is_a_dir(dir) != 0) {
        write(1, dir, my_strlen(dir));
        write(1, ": Not a directory.\n", 19);
        return;
    }
    if (chdir(dir) == -1) {
        write(1, dir, my_strlen(dir));
        write(1, ": Permission denied.\n", 21);
        return;
    }
    intern_setenv("OLDPWD=", temp, head_env);
    getcwd (temp, my_strlen(temp));
    intern_setenv("PWD=", temp, head_env);
}

void my_cd (char ** args, env_t *head_env)
{
    char *dir = NULL;
    char temp[256] = "";
    getcwd(temp, sizeof(temp));
    if (my_str_str_len(args) > 2) {
        write(1, "cd: Too many arguments.\n", 24);
        return;
    }
    if (args[1] == NULL) {
        dir = get_env_variable("HOME=", head_env);
        if (dir != NULL)
            dir += 5;
        return set_pwd (dir, temp, head_env);
    }
    if (my_strlen(args[1]) == 1 && args[1][0] == '-') {
        dir = get_env_variable("OLDPWD=", head_env);
        if (dir != NULL)
            dir += 7;
        return set_pwd (dir, temp, head_env);
    }
    set_pwd ((dir = args[1]), temp, head_env);
}
