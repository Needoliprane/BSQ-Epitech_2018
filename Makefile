##
## EPITECH PROJECT, 2017
## make
## File description:
## make
##

CC	=	gcc

NAME	=	bsq

SRC	=	src/get_file.c					\
		src/my_algo.c					\
		lib/my_strdup.c					\
		lib/free.c					\
		lib/my_getnbr.c					\
		lib/my_putstr.c					\
		lib/my_strlen.c					\
		lib/my_str_to_word_array.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/ -W -Wextra -Wall

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) src/main.c


clean:
		rm -f $(OBJ)

coverage_clean:
		rm -f *.gc*
		rm -f src/*.gc*

fclean: 	clean coverage_clean
		rm -f $(NAME)
		rm -f ./script_test/$(NAME)

re:		fclean all

.PHONY:		all clean fclean re
