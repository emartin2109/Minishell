/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    #include "include.h"

char **my_str_to_word_array (char * str);
char *my_strcat (char *dest ,char const *src);
char *my_strcat_no_free (char *dest, char const *src);
int my_strcmp (char const *s1 ,char const *s2);
int is_in_list (char const *list, char const c);
char * my_strcpy (char * dest , char const *src);
int my_strlen (char const *str);
int my_str_str_len (char **str);

#endif /* !LIB_H_ */
