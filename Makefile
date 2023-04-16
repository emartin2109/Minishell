##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	lib/my/src/my_strcat.c				\
		lib/my/src/my_strcmp.c				\
		lib/my/src/my_strcpy.c				\
		lib/my/src/my_strlen.c				\
		lib/my/src/my_str_to_word_array.c	\
		src/main_functions/handle_input.c	\
		src/main_functions/main.c			\
		src/main_functions/mysh.c			\
		src/my_command/my_cd.c				\
		src/my_command/my_env.c				\
		src/my_command/my_setenv.c			\
		src/my_command/my_unsetenv.c		\
		src/my_command/my_exec.c			\
		src/utils/get.c						\
		src/utils/utils.c



OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CPPFLAGS += -I./include

CFLAGS = -g -Werror -Wextra -Wshadow -Wimplicit

all:	$(NAME)
PHONY	+= all

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
PHONY	+= clean

fclean:	clean
	rm -f $(NAME)
PHONY	+= fclean

re:	fclean all
PHONY	+= re

debug: CFLAGS += -DDEBUG
debug: fclean $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)
PHONY	+= debug

.PHONY:	$(PHONY)
