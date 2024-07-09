#### MAIN SETTINGS ####

# Compiler to be used
CC				:= cc

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -pedantic -O3

# Libraries to be linked (if any)
LIBS			:= -L./lib/libft/ -lft
LIBS			+= -L./lib/ft_printf/ -lftprintf
LIBS			+= -lreadline

# Include directories
INCLUDES		:= -Iinclude/ -Ilib/libft/
INCLUDES		+= -Ilib/ft_printf/includes/

# Target executable
TARGET			:= minishell

# Source files directory
SRC_DIR			:= src/

# Source files
SRC_FILES		+= execution/main.c
SRC_FILES		+= execution/command.c
SRC_FILES		+= execution/pipeline.c
SRC_FILES		+= execution/heredoc.c

SRC_FILES		+= builtins/echo.c
SRC_FILES		+= builtins/pwd.c
SRC_FILES		+= builtins/cd.c
SRC_FILES		+= builtins/env.c
SRC_FILES		+= builtins/export.c
SRC_FILES		+= builtins/unset.c

SRC_FILES		+= utils/envp_utils.c
SRC_FILES		+= utils/cmd_error_utils.c
SRC_FILES		+= utils/misc.c
SRC_FILES		+= utils/cmd_misc_utils.c

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

.DEFAULT_GOAL	:= all

quick: ## Run recipes simultaneously
	@$(MAKE) -j all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo -n "[build] "
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo -n "[link] "
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	-@echo -n "$(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_PATH)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_PATH)

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@echo -n "[clean] "
	$(RM) $(OBJ_FILES)
	@echo -n "[clean] "
	$(RM) -r $(OBJ_DIR)
	@echo -n "[clean] "
	$(RM) $(DEPENDS)
	@echo -n "[clean] "
	$(RM) -r $(DEP_DIR)
	@(test -s $(LIBFT_LIB) && $(MAKE) -C $(LIBFT_PATH) clean) ||:
	@(test -s $(FT_PRINTF_LIB) && $(MAKE) -C $(FT_PRINTF_PATH) clean) ||:

fclean: clean ## Restore project to initial state
	@echo -n "[clean] "
	$(RM) $(TARGET)
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

rclear: ## Clear the terminal and run `make`
	echo -ne "\033c" && make

.PHONY: all re clean fclean help test rclear ftprintf libft

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
