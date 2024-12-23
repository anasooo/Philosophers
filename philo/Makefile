CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g -lpthread -fsanitize=thread
SRCS = main.c \
	  utils.c \
	  parsing.c \
	  initialization.c \
	  ft_time.c \
	  setters.c \
	  ft_free.c \
	  ft_routine.c \
	  print.c \
	  ft_threads.c \
	  forks.c \
	  ft_monitor.c \
	  ft_check.c \

OBJ = $(SRCS:.c=.o)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
