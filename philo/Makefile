
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g #fsanitize=thread -pthread
SRC = main.c \
	  utils.c \
	  initialization.c \
	  threads.c\
	  time.c\
	  print.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

NAME = philo

all: $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re