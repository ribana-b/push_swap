# ========================================================================== #

# <-- Color Library --> #

# <-- Text Color --> #
T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

# <-- Text Style --> #
BOLD = \033[1m
ITALIC = \033[2m
UNDERLINE = \033[3m
STRIKETHROUGH = \033[4m

# <-- Background Color --> #
B_RED = \033[31m
B_BLACK = \033[30m
B_GREEN = \033[32m
B_YELLOW = \033[33m
B_BLUE = \033[34m
B_MAGENTA = \033[35m
B_CYAN = \033[36m
B_WHITE = \033[37m

# <-- Reset Everything --> #
RESET = \033[0m

# ========================================================================== #

# <-- Output Name --> #
NAME = push_swap

# <-- Compilation Command --> #
CC = cc

# <-- Compilation Flags --> #
ifdef WITH_DEBUG
	CFLAGS = -Wall -Wextra -Werror -ggdb
else
	CFLAGS = -Wall -Wextra -Werror
endif

# <-- Remove Command --> #
RM = rm -rf

# <-- Include Library --> #
INCLUDE = -I ./include -I $(BFL_DIR)include

# <-- Link BFL --> #
LIBRARY = -L./BFL/ -lbfl

# <-- Directories --> #
BFL_DIR = BFL/
SRC_DIR = src/
UTILS_DIR = src/utils/
MOVEMENT_DIR = src/movement/
OBJ_DIR = obj/

DEBUG_DIR = src/debug/
SORT_DIR = src/sort/

# <-- Files --> #
SRC_FILES = main.c
UTILS_FILES = checker.c \
				stack_manipulation.c \
				parser.c
MOVEMENT_FILES = push_stack.c \
				reverse_rotate_stack.c \
				rotate_stack.c \
				swap_stack.c

DEBUG_FILES = debug.c
SORT_FILES = sort_three_to_six.c

# <-- Directories + Files --> #
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
MOVEMENT = $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_FILES))

DEBUG = $(addprefix $(DEBUG_DIR), $(DEBUG_FILES))
SORT = $(addprefix $(SORT_DIR), $(SORT_FILES))

# <-- Objects --> #
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
		$(patsubst $(DEBUG_DIR)%.c, $(OBJ_DIR)%.o, $(DEBUG)) \
		$(patsubst $(SORT_DIR)%.c, $(OBJ_DIR)%.o, $(SORT)) \
		$(patsubst $(MOVEMENT_DIR)%.c, $(OBJ_DIR)%.o, $(MOVEMENT))

# ========================================================================== #

# <-- Project's Target --> #
all: $(NAME)

# <-- Program/Library Creation --> #
ifdef WITH_DEBUG
$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s debug -C $(BFL_DIR)
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBRARY)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
else
$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C $(BFL_DIR)
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBRARY)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
endif

# <-- Objects Directory Creation --> #
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# <-- Objects Creation --> #
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(DEBUG_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(SORT_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(MOVEMENT_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJ_DIR)
	@echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# <-- Clean Execution + push_swap Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(BFL_DIR)
	@echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# <-- Fclean Execution + All Execution --> #
re: fclean all

# <-- Debug --> #
debug: fclean
	@make -s WITH_DEBUG=1

# <-- Targets Declaration --> #
.PHONY = all clean debug fclean re

# ========================================================================== #
