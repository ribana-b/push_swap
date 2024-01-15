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

# <-- Library's Name --> #
NAME = push_swap

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = -Wall -Wextra -Werror

# <-- Remove Command -->#
RM = rm -rf

# <-- Directories --> #
BFL_DIR = BFL/
SRC_DIR = src/
UTILS_DIR = utils/
OBJ_DIR = obj/

DEBUG_DIR = debug/
SORT_DIR = sort/

# <-- Files --> #
SRC_FILES = push_swap.c
UTILS_FILES = push_stack.c \
			reverse_rotate_stack.c \
			rotate_stack.c \
			stack_manipulation.c \
			swap_stack.c \
			checker.c

DEBUG_FILES = debug.c
SORT_FILES = sort_three_to_six.c

# <-- Directories + Files --> #
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

DEBUG = $(addprefix $(DEBUG_DIR), $(DEBUG_FILES))
SORT = $(addprefix $(SORT_DIR), $(SORT_FILES))

# <-- Objects --> #
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
		$(patsubst $(DEBUG_DIR)%.c, $(OBJ_DIR)%.o, $(DEBUG)) \
		$(patsubst $(SORT_DIR)%.c, $(OBJ_DIR)%.o, $(SORT))

# ========================================================================== #

# <-- Main Target --> #
all: $(NAME)

# <-- Program/Library Creation --> #
$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C $(BFL_DIR)
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
	@$(CC) $(OBJ) $(BFL_DIR)/bfl.a -o $(NAME)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"

# <-- Object Directory Creation --> #
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# <-- Objects Creation --> #
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(DEBUG_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(SORT_DIR)%.c
	@echo "🔨 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJ_DIR)
	@echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# <-- Clean Execution + push_swap Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(BFL_DIR)
	@echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# <-- Fclean Execution + All Execution --> #
re: fclean all

# <-- Color testing --> #

colortesting:
	@echo "$(T_BLACK)Black text"
	@echo "$(T_RED)Red text"
	@echo "$(T_GREEN)Green text"
	@echo "$(T_YELLOW)Yellow text"
	@echo "$(T_BLUE)Blue text"
	@echo "$(T_MAGENTA)Magenta text"
	@echo "$(T_CYAN)Cyan text"
	@echo "$(T_WHITE)White text$(RESET)"
	@echo "$(BOLD)"
	@echo "$(T_BLACK)Bold Black text"
	@echo "$(T_RED)Bold Red text"
	@echo "$(T_GREEN)Bold Green text"
	@echo "$(T_YELLOW)Bold Yellow text"
	@echo "$(T_BLUE)Bold Blue text"
	@echo "$(T_MAGENTA)Bold Magenta text"
	@echo "$(T_CYAN)Bold Cyan text"
	@echo "$(T_WHITE)Bold White text$(RESET)"

# <-- Targets Declaration --> #
.PHONY = all clean fclean re colortesting

# ========================================================================== #
