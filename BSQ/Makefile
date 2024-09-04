NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes

SRC =	srcs/ft_atoi.c \
	srcs/ft_read_file.c \
	srcs/ft_split.c \
	srcs/ft_solve.c \
	srcs/ft_validate_map.c \
	srcs/ft_resolver.c \
	srcs/ft_map.c \
	srcs/check_first_line.c \
	srcs/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
