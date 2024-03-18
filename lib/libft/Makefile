#### MAIN SETTINGS ####

# Compiler to be used
CC				:= clang

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -O3

# Libraries to be linked (if any)
LIBS			:=

# Include directories
INCLUDES		:= -I./

# Target executable
TARGET			:= libft.a

# Source files directory
SRC_DIR			:= ./

# Source files
SRC_FILES		+= ft_memset.c			# Memset
SRC_FILES		+= ft_memcpy.c			# Memcpy
SRC_FILES		+= ft_memmove.c			# Memmove
SRC_FILES		+= ft_isalnum.c			# Isalnum
SRC_FILES		+= ft_isalpha.c			#
SRC_FILES		+= ft_isascii.c			#
SRC_FILES		+= ft_isdigit.c			#
SRC_FILES		+= ft_isprint.c			#
SRC_FILES		+= ft_strlen.c			#
SRC_FILES		+= ft_bzero.c			#
SRC_FILES		+= ft_strlcpy.c			#
SRC_FILES		+= ft_strlcat.c			#
SRC_FILES		+= ft_toupper.c			#
SRC_FILES		+= ft_tolower.c			#
SRC_FILES		+= ft_strchr.c			#
SRC_FILES		+= ft_strrchr.c			#
SRC_FILES		+= ft_strncmp.c			#
SRC_FILES		+= ft_memchr.c			#
SRC_FILES		+= ft_memcmp.c			#
SRC_FILES		+= ft_strnstr.c			#
SRC_FILES		+= ft_atoi.c			#
SRC_FILES		+= ft_calloc.c			#
SRC_FILES		+= ft_strdup.c			#
SRC_FILES		+= ft_substr.c			#
SRC_FILES		+= ft_strjoin.c			#
SRC_FILES		+= ft_strtrim.c			#
SRC_FILES		+= ft_split.c			#
SRC_FILES		+= ft_itoa.c			#
SRC_FILES		+= ft_strmapi.c			#
SRC_FILES		+= ft_striteri.c		#
SRC_FILES		+= ft_putchar_fd.c		#
SRC_FILES		+= ft_putstr_fd.c		#
SRC_FILES		+= ft_putendl_fd.c		#
SRC_FILES		+= ft_putnbr_fd.c		#
SRC_FILES		+= ft_lstnew_bonus.c	#
SRC_FILES		+= ft_lstadd_front_bonus.c	#
SRC_FILES		+= ft_lstsize_bonus.c		#
SRC_FILES		+= ft_lstlast_bonus.c		#
SRC_FILES		+= ft_lstadd_back.c			#
SRC_FILES		+= ft_lstdelone_bonus.c		#
SRC_FILES		+= ft_lstclear_bonus.c		#
SRC_FILES		+= ft_lstiter_bonus.c		#
SRC_FILES		+= ft_lstmap_bonus.c		#
SRC_FILES		+= deque/deque_back.c	#
SRC_FILES		+= deque/deque_front.c	#
SRC_FILES		+= deque/deque_emplace_back.c	#
SRC_FILES		+= deque/deque_emplace_front.c	#
SRC_FILES		+= deque/deque_push_back.c		#
SRC_FILES		+= deque/deque_push_front.c		#
SRC_FILES		+= deque/deque_pop_back.c		#
SRC_FILES		+= deque/deque_pop_front.c		#
SRC_FILES		+= deque/deque_empty.c			#
SRC_FILES		+= deque/deque_size.c			#
SRC_FILES		+= deque/deque_swap.c			#

# Object files directory
OBJ_DIR			:= obj/

# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Dependency files directory
DEP_DIR			:= dep/

# Dependency files
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)%.d, $(OBJ_FILES))
-include $(DEPENDS)

#### SHELL COMMANDS ####

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch

#### LOCAL LIBRARIES ####

#### DEBUG SETTINGS ####

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif

#### TARGET COMPILATION ####

.DEFAULT_GOAL	:= all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo -n "build]: $(CYAN)"
	@echo "$(BOLD)compile$(RESET)$(CYAN) $@ $(RESET)"
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES) ## $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo -n "build]: $(GREEN)"
	@echo "$(BOLD)Archive$(RESET)$(GREEN) $(TARGET) $(RESET)"
	@ar rcs $@ $^
	@echo "$(BLUE)[$(TARGET) - info]: $(GREEN)$(BOLD)Build finished!$(RESET)"
	-@echo -n "$(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@$(RM) $(OBJ_FILES)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)[$(TARGET) - clean]: $(YELLOW)$(BOLD)Remove objects$(RESET)"
	@$(RM) $(DEPENDS)
	@$(RM) -r $(DEP_DIR)
	@echo "$(BLUE)[$(TARGET) - clean]: $(YELLOW)$(BOLD)Remove dependecies$(RESET)"

fclean: clean ## Restore project to initial state
	@$(RM) $(TARGET)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo "fclean]: $(YELLOW)$(BOLD)Remove$(RESET)$(YELLOW) \`$(TARGET)\`$(RESET)"

re: fclean all ## Rebuild project

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help

#### COLORS ####
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m
