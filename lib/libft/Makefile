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
SRC_FILES		+= memory/ft_memset.c			### Memory ###
SRC_FILES		+= memory/ft_memcpy.c			# Memory
SRC_FILES		+= memory/ft_memmove.c			# Memory
SRC_FILES		+= memory/ft_memchr.c			# Memory
SRC_FILES		+= memory/ft_memcmp.c			# Memory
SRC_FILES		+= memory/ft_calloc.c			# Memory
SRC_FILES		+= memory/ft_malloc.c			# Memory

SRC_FILES		+= string/ft_strlen.c			### String ###
SRC_FILES		+= string/ft_strlcpy.c			# String
SRC_FILES		+= string/ft_strlcat.c			# String
SRC_FILES		+= string/ft_strrchr.c			# String
SRC_FILES		+= string/ft_strncmp.c			# String
SRC_FILES		+= string/ft_strnstr.c			# String
SRC_FILES		+= string/ft_strdup.c			# String
SRC_FILES		+= string/ft_substr.c			# String
SRC_FILES		+= string/ft_strjoin.c			# String
SRC_FILES		+= string/ft_strtrim.c			# String
SRC_FILES		+= string/ft_split.c			# String
SRC_FILES		+= string/ft_strmapi.c			# String
SRC_FILES		+= string/ft_striteri.c			# String
SRC_FILES		+= string/ft_strchr.c			# String

SRC_FILES		+= utils/ft_isalnum.c			### Utils ###
SRC_FILES		+= utils/ft_isalpha.c			# Utils
SRC_FILES		+= utils/ft_isascii.c			# Utils
SRC_FILES		+= utils/ft_isdigit.c			# Utils
SRC_FILES		+= utils/ft_isprint.c			# Utils
SRC_FILES		+= utils/ft_bzero.c				# Utils
SRC_FILES		+= utils/ft_toupper.c			# Utils
SRC_FILES		+= utils/ft_tolower.c			# Utils
SRC_FILES		+= utils/ft_atoi.c				# Utils
SRC_FILES		+= utils/ft_itoa.c				# Utils

SRC_FILES		+= put/ft_putchar_fd.c			### Put ###
SRC_FILES		+= put/ft_putstr_fd.c			# Put
SRC_FILES		+= put/ft_putendl_fd.c			# Put
SRC_FILES		+= put/ft_putnbr_fd.c			# Put

SRC_FILES		+= list/ft_lstnew_bonus.c		### List ###
SRC_FILES		+= list/ft_lstadd_front_bonus.c	# List
SRC_FILES		+= list/ft_lstsize_bonus.c		# List
SRC_FILES		+= list/ft_lstlast_bonus.c		# List
SRC_FILES		+= list/ft_lstadd_back.c		# List
SRC_FILES		+= list/ft_lstdelone_bonus.c	# List
SRC_FILES		+= list/ft_lstclear_bonus.c		# List
SRC_FILES		+= list/ft_lstiter_bonus.c		# List
SRC_FILES		+= list/ft_lstmap_bonus.c		# List

SRC_FILES		+= deque/deque_back.c			### Deque ###
SRC_FILES		+= deque/deque_front.c			# Deque
SRC_FILES		+= deque/deque_emplace_back.c	# Deque
SRC_FILES		+= deque/deque_emplace_front.c	# Deque
SRC_FILES		+= deque/deque_push_back.c		# Deque
SRC_FILES		+= deque/deque_push_front.c		# Deque
SRC_FILES		+= deque/deque_pop_back.c		# Deque
SRC_FILES		+= deque/deque_pop_front.c		# Deque
SRC_FILES		+= deque/deque_empty.c			# Deque
SRC_FILES		+= deque/deque_size.c			# Deque
SRC_FILES		+= deque/deque_swap.c			# Deque

SRC_FILES		+= hash_table/hashtable.c		### Hash Table ###
SRC_FILES		+= hash_table/ht_utils.c		# Hash Table

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
	@echo "$(BLUE)[$(TARGET) -" \
	"build]:$(CYAN)" \
	"$(BOLD)compile$(RESET)$(CYAN) $@ $(RESET)"
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES) ## $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(BLUE)[$(TARGET) -" \
	"build]:$(GREEN)" \
	"$(BOLD)Archive$(RESET)$(GREEN) $(TARGET) $(RESET)"
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
