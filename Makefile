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
RM = rm -f

# <-- Directories --> #
SRC_DIR = src/
UTILS_DIR = utils/

# <-- Files --> #
SRC_FILES	=	push_swap.c
UTILS_FILES	=	stack_manipulation.c \
				swap_stack.c \
				push_stack.c \
				rotate_stack.c \
				reverse_rotate_stack.c

# <-- Directories + Files --> #
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

# <-- Objects --> #
OBJ_SRC = $(SRC:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

# ========================================================================== #

# <-- Main Target --> #
all: $(NAME)

# <--Library Creation--> #
$(NAME): $(OBJ_SRC) $(OBJ_UTILS)
	@echo "$(T_YELLOW)$(BOLD)Objects created successfully$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_UTILS) -o $(NAME)
	@echo "$(T_YELLOW)$(BOLD)$(NAME) created successfully$(RESET)"

# <-- Objects Creation --> #
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# <-- Objects Destruction --> #
clean:
	$(RM) $(OBJ_SRC) $(OBJ_UTILS)
	@echo "$(T_RED)$(BOLD)Objects destroyed successfully$(RESET)"

# <- Clean Execution + push_swap Destruction -> #
fclean: clean
	$(RM) $(NAME)
	@echo "$(T_RED)$(BOLD)$(NAME) destroyed successfully$(RESET)"

# <- Fclean Execution + All Execution -> #
re: fclean all

run_leaks: re
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./$(NAME)

# <- Targets Declaration -> #
.PHONY = all clean fclean re run_leaks

# ========================================================================== #
