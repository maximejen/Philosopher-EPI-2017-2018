##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## nm
##

CC 	=	gcc

RM 	=	rm -f

NAME	=	philo

SRC	=	main.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS 	=	-I include -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
