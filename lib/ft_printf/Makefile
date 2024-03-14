# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:26:36 by astavrop          #+#    #+#              #
#    Updated: 2023/12/17 17:11:33 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
NAME		= libftprintf.a

SRCS		= src/parser.c ft_printf.c \
				src/formatter_c.c src/formatter_s.c src/formatter_di.c \
				src/formatter_u.c src/formatter_xX.c src/formatter_ptr.c\
				utils/ft_putchar_fd.c utils/ft_putendl_fd.c utils/ft_putnbr_fd.c \
				utils/ft_putstr_fd.c utils/ft_strlen.c utils/ft_strdup.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

.PHONY: all clean fclean re fclean-test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
