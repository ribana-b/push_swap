# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

BOLD = \033[1m
ITALIC = \033[2m
UNDERLINE = \033[3m
STRIKETHROUGH = \033[4m

B_RED = \033[31m
B_BLACK = \033[30m
B_GREEN = \033[32m
B_YELLOW = \033[33m
B_BLUE = \033[34m
B_MAGENTA = \033[35m
B_CYAN = \033[36m
B_WHITE = \033[37m

CLEAR_LINE = \033[1F\r\033[2K

RESET = \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME = push_swap

CC = cc

ifdef WITH_DEBUG
	CFLAGS = -Wall -Wextra -Werror -ggdb
else
	CFLAGS = -Wall -Wextra -Werror
endif

RM = rm -rf

INCLUDE = -I ./include -I $(BFL_DIR)include

LIBRARY = -L./BFL/ -lbfl

BFL_DIR = BFL/
SRC_DIR = src/
UTILS_DIR = src/utils/
MOVEMENT_DIR = src/movement/
OBJ_DIR = obj/
BIN_DIR = bin/

SORT_DIR = src/sort/

SRC_FILES = main.c
UTILS_FILES = check_sorted.c \
				stack_manipulation.c \
				parser.c \
				info.c
MOVEMENT_FILES = push_stack.c \
				reverse_rotate_stack.c \
				rotate_stack.c \
				swap_stack.c \
				best_move.c

SORT_FILES = sort_numbers.c \
				sort_cost.c


SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
MOVEMENT = $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_FILES))

SORT = $(addprefix $(SORT_DIR), $(SORT_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
		$(patsubst $(SORT_DIR)%.c, $(OBJ_DIR)%.o, $(SORT)) \
		$(patsubst $(MOVEMENT_DIR)%.c, $(OBJ_DIR)%.o, $(MOVEMENT))

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(BIN_DIR) $(BIN_DIR)$(NAME)

ifdef WITH_DEBUG
$(BIN_DIR)$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s debug -C $(BFL_DIR)
	$(OBJ_MSG)
	@$(CC) -o $@ $(OBJ) $(INCLUDE) $(LIBRARY)
	$(OUTPUT_MSG)
else
$(BIN_DIR)$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C $(BFL_DIR)
	$(OBJ_MSG)
	@$(CC) -o $@ $(OBJ) $(INCLUDE) $(LIBRARY)
	$(OUTPUT_MSG)
endif

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c | $(OBJ_DIR)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(SORT_DIR)%.c | $(OBJ_DIR)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(MOVEMENT_DIR)%.c | $(OBJ_DIR)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"

fclean: clean
	@$(RM) $(BIN_DIR)$(NAME) tags
	@make fclean -s -C $(BFL_DIR)
	@echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

re: fclean all

debug:
	@make -s WITH_DEBUG=1

tags:
	@$(shell find . ! -path "./checker_bonus/*" -type f \( -name "*c" -o -name "*.h" \) > temp)
	@ctags -F $(shell cat temp)
	@rm temp

bonus:
	@make -s -C checker_bonus

.PHONY: all bonus clean debug fclean re tags
