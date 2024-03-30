#### MAIN SETTINGS ####

# Compiler to be used
CC				:= clang

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -pedantic -O3

# Libraries to be linked (if any)
LIBS			:= -L./lib/libft/ -lft
LIBS			+= -L./lib/ft_printf/ -lftprintf

# Include directories
INCLUDES		:= -Iinclude/ -Ilib/libft/
INCLUDES		+= -Ilib/ft_printf/includes/

# Target executable
TARGET			:= minishell

# Source files directory
SRC_DIR			:= src/

# Source files
SRC_FILES		+= main.c						# Main
SRC_FILES		+= holy_executor/execute.c		# Executor
SRC_FILES		+= holy_executor/pipe.c			# Pipes
SRC_FILES		+= builtins/echo.c				# Echo
SRC_FILES		+= builtins/cd.c				# CD
SRC_FILES		+= utils/free_utils.c			# Utils
SRC_FILES		+= utils/error_utils.c			# Utils
SRC_FILES		+= utils/wait_utils.c			# Utils
SRC_FILES		+= utils/execution_utils.c		# Utils
SRC_FILES		+= utils/debug_utils.c			# TODO: Delete

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

FT_PRINTF_PATH	:= lib/ft_printf/
FT_PRINTF_LIB	:= $(FT_PRINTF_PATH)libftprintf.a

LIBFT_PATH		:= lib/libft/
LIBFT_LIB		:= $(LIBFT_PATH)libft.a

#### DEBUG SETTINGS ####

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif

#### TARGET COMPILATION ####

.DEFAULT_GOAL	:= quick

quick: ## Run recipes simultaneously
	@$(MAKE) -j all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo "$(BLUE)[$(TARGET) -" \
	"build]:$(CYAN)" \
	"$(BOLD)compile$(RESET)$(CYAN) $@ $(RESET)"
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(BLUE)[$(TARGET) -" \
	"build]:$(GREEN)" \
	"$(BOLD)Link$(RESET)$(GREEN) $(TARGET) $(RESET)"
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	@echo "$(BLUE)[$(TARGET) -" \
	"info]: $(GREEN)$(BOLD)Build finished!$(RESET)"
	-@echo -n "$(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_PATH)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_PATH)

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@$(RM) $(OBJ_FILES)
	@$(RM) -r $(OBJ_DIR)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo "clean]: $(YELLOW)$(BOLD)Remove objects$(RESET)"
	@$(RM) $(DEPENDS)
	@$(RM) -r $(DEP_DIR)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo "clean]: $(YELLOW)$(BOLD)Remove dependecies$(RESET)"
	@(test -s $(LIBFT_LIB) && $(MAKE) -C $(LIBFT_PATH) clean) ||:
	@(test -s $(FT_PRINTF_LIB) && $(MAKE) -C $(FT_PRINTF_PATH) clean) ||:

fclean: clean ## Restore project to initial state
	@$(RM) $(TARGET)
	@echo -n "$(BLUE)[$(TARGET) - "
	@echo -n "fclean]: $(YELLOW)"
	@echo "$(BOLD)Remove$(RESET)$(YELLOW) \`$(TARGET)\`$(RESET)"
	@(test -s $(LIBFT_LIB) && $(MAKE) -C $(LIBFT_PATH) fclean) ||:
	@(test -s $(FT_PRINTF_LIB) && $(MAKE) -C $(FT_PRINTF_PATH) fclean) ||:
	@(test -d test/ && $(MAKE) -C test/ fclean) ||:

re: fclean all ## Rebuild project

test: ## Run tests
	@(test ! -d test/ && echo "$(RED)There were no tests that I could find.$(RESET)") ||:
	@$(MAKE) -C test/

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help test

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
