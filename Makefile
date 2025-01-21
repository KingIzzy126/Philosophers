NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3 -I./includes/ -fsanitize=thread

SRCS =	action.c \
		parse.c  \
		utils.c \
		initialization.c \
		threads.c \
		main.c \
		monitor.c \

SRC = $(addprefix ./srcs/,$(SRCS))
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re