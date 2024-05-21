# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 12:57:10 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/05/21 13:02:38 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #

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

CLEAR_LINE = \033[1F\r\033[2K

RESET = \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME = checker 

CC = cc

ifdef WITH_DEBUG
	CFLAGS = -Wall -Wextra -Werror -ggdb
else
	CFLAGS = -Wall -Wextra -Werror
endif

RM = rm -rf

CPPFLAGS = -I ./include -I $(BFL_DIR)include

LIBRARY = -L$(BFL_DIR) -lbfl

BFL_DIR = ../BFL/
SRC_DIR = src/
UTILS_DIR = src/utils/
MOVEMENT_DIR = src/movement/
OBJ_DIR = obj/
BIN_DIR = bin/

SRC_FILES = checker_bonus.c
UTILS_FILES = check_sorted_bonus.c \
				stack_manipulation_bonus.c \
				parser_bonus.c \
				info_bonus.c
MOVEMENT_FILES = push_stack_bonus.c \
				reverse_rotate_stack_bonus.c \
				rotate_stack_bonus.c \
				swap_stack_bonus.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
MOVEMENT = $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
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
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LIBRARY)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
else
$(BIN_DIR)$(NAME): $(OBJ_DIR) $(OBJ)
	@make -s -C $(BFL_DIR)
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Push Swap Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LIBRARY)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
endif

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(MOVEMENT_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(BIN_DIR)$(NAME) tags
	@make fclean -s -C $(BFL_DIR)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@echo
	@make -s all

debug:
	@make -s WITH_DEBUG=1

tags:
	@$(shell find . -type f -name "*.c" -o -name "*.h" > temp)
	@ctags -F $(shell cat temp)
	@rm temp

.PHONY: all clean debug fclean re tags
