# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 20:01:54 by astavrop          #+#    #+#              #
#    Updated: 2024/02/17 20:43:57 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
NAME =			libft.a
INCLUDES		= -I.

SRC_FILES =		ft_memset.c ft_memcpy.c ft_memmove.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				deque/deque_back.c deque/deque_emplace_back.c deque/deque_emplace_front.c \
				deque/deque_empty.c deque/deque_front.c deque/deque_pop_back.c deque/deque_pop_front.c \
				deque/deque_push_back.c deque/deque_push_front.c deque/deque_size.c deque/deque_swap.c
OBJS =			$(SRC_FILES:.c=.o)

.DEFAULT_GOAL := all

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	ar rcs $@ $^


clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
