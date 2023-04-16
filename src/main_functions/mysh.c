/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** mysh
*/

#include "include.h"
#include "lib.h"
#include "get.h"
#include "main_functions.h"
#include "my_command.h"
#include "utils.h"

char ** argument_parser (char **words, env_t *head_env)
{
    int i = -1;
    char *temp = NULL;
    char *dir = get_env_variable("HOME=", head_env);
    if (dir != NULL)
        dir += 5;
    while (words[++i]) {
        if (words[i][0] == '~') {
            temp = my_strcat_no_free(dir, words[i] + 1);
            free(words[i]);
            words[i] = temp;
        }
    }
    return words;
}

static void main_loop (int action_val, int ac, char **av, env_t *head_env)
{
    while (action_val != 0 && action_val != -1) {
        write(1, "$> ", 3);
        char **words = my_str_to_word_array(get_input());
        if (words == NULL) {
            my_free_str_str(words);
            write (1, "exit\n", 5);
            return;
        }
        if (words[0] == NULL) {
            free(words);
            continue;
        }
        words = argument_parser(words, head_env);
        action_val = handle_command(words, head_env);
        if (action_val == 1)
            action_val = exec_pre_build_command(words, head_env);
        my_free_str_str(words);
    }
}

int my_sh (int ac, char **av, env_t *head_env)
{
    int action_val = 1;
    main_loop(action_val, ac, av, head_env);
    my_free_env_t(head_env);
    return SUCCESS;
}
