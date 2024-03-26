# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 17:41:15 by astavrop          #+#    #+#              #
#    Updated: 2024/03/25 19:05:30 by ltreser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -O3
LIBS				:= -Llib/ft_printf/ -lftprintf -Llib/libft/ -lft
LIBS				+= -lreadline
INCLUDES			:= -I./include/ -Ilib/ft_printf/includes -Ilib/libft/ -I.
NAME				:= minishell


CFILES				+= main.c						# Main
CFILES				+= prompt/prompt.c				# Main
CFILES				+= init.c						# Main
CFILES				+= lexer/lexer.c				# Lexer


OBJ_DIR				:= ./obj/
OBJS				:= $(patsubst %.c, $(OBJ_DIR)%.o, $(CFILES))


DEPS				:= $(OBJS:.o=.d)


FT_PRINTF_PATH		= ./lib/ft_printf/
FT_PRINTF_BIN		= $(FT_PRINTF_PATH)libftprintf.a


LFT_PATH			= ./lib/libft/
LFT_BIN				= $(LFT_PATH)libft.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -O0
endif

all: $(NAME)

.DEFAULT_GOAL := all


-include $(DEPS)


$(OBJ_DIR)%.o: */%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS) $(LFT_BIN) $(FT_PRINTF_BIN)
	@echo -n "\033[32;49;3m... Compiling code ...\033[0m\r"
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS)
	@echo "\033[32;49;1m>>>   Done!   <<<\033[0m          "


$(FT_PRINTF_BIN):
	@echo -n "\033[32;49;3m... Making ft_printf ...\033[0m\r"
	@$(MAKE) -sC $(FT_PRINTF_PATH)
	@echo "\033[32;49;1m> ft_printf ready!         \033[0m"


$(LFT_BIN):
	@echo -n "\033[32;49;3m... Making libft ...\033[0m\r"
	@$(MAKE) -sC $(LFT_PATH)
	@echo "\033[32;49;1m> libft ready!             \033[0m"


clean:
	@$(MAKE) -sC $(FT_PRINTF_PATH) clean
	@$(MAKE) -sC $(LFT_PATH) clean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[32;1mObjects cleand!\033[0m"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_PATH) fclean
	@$(MAKE) -sC $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[32;1mEverything cleand!\033[0m"

re: fclean all


.PHONY: all clean fclean re
