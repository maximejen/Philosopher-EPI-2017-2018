##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## philo
##

CC	=	gcc

RM	=	rm -f

NAME	=	philo

SRC	=	main.c		\
		philo_action.c	\
		manipulate.c	\
		philo.c		\
		chopstick.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include -W -Wall -Wextra

LDFLAGS	=	-L. -lriceferee -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
