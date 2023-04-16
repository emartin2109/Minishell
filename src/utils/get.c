/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** get
*/

#include "include.h"
#include "lib.h"

char *get_input (void)
{
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    read = getline(&line, &len, stdin);
    if (read == -1) {
        if (line != NULL)
            free(line);
        return NULL;
    }
    return line;
}

char *get_path (char *path_list, char *command)
{
    int i = 0;
    while (path_list[i] && path_list[i] != '=')
        i++;
    while (path_list[i++]) {
        char *temp = malloc(my_strlen(path_list) * sizeof(char));
        int j = 0;
        while (path_list[i] != ':' && path_list[i])
            temp[j++] = path_list[i++];
        temp[j] = '\0';
        temp = my_strcat(temp, "/\0");
        temp = my_strcat(temp, command);
        if (open(temp, O_RDONLY) != -1)
            return temp;
        free(temp);
    }
    return NULL;
}

char *get_env_variable(char *name, env_t *head_env)
{
    env_t *current_env = head_env;
    int verif = 0;
    while (current_env != NULL) {
        if (!my_strcmp(name, current_env->variable)) {
            verif = 1;
            break;
        }
        current_env = current_env->next;
    }
    if (verif == 0)
        return NULL;
    return current_env->variable;
}
