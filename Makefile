NAME	= pilosophers
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

HEADER	= philo.h

SRC		= action.c main.c init.c start_philo.c utilise.c

all: $(NAME)
$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	$(RM) $(NAME)

re : fclean all
