# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 17:24:11 by achu              #+#    #+#              #
#    Updated: 2024/09/04 13:43:48 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a
SRCDIR = src
INCDIR = includes

SRC =	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c \
	srcs/ft_swap.c

OBJS = ${SRC:.c=.o}

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(LIB)

re:	fclean all

.PHONY: all clean fclean re
