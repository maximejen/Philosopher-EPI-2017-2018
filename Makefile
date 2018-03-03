##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## philo
##

CC 	=	gcc

RM 	=	rm -f

NAME	=	philo

SRC	=	main.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS 	=	-I include -W -Wall -Wextra

LDFLAGS	=	-L. -lriceferee -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re