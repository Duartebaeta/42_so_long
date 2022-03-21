NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
LBX_FLAGS := -lmlx -framework OpenGL -framework AppKit

PATH_INCLUDES := ./includes
PATH_LIBS := ./libs
PATH_SRCS := ./srcs
PATH_BUILD := build
PATH_OBJS := $(PATH_BUILD)/objs
PATH_LIBFT := $(PATH_LIBS)/libft

BIN := ./$(NAME)
SRCS := $(PATH_SRCS)/main.c \
		$(PATH_SRCS)/read_map.c \
		$(PATH_SRCS)/check_map.c \
		$(PATH_SRCS)/custom_error.c \
		$(PATH_SRCS)/init.c \
		$(PATH_SRCS)/utils.c \
		$(PATH_SRCS)/moves.c

OBJS := $(subst .c,.o,$(subst $(PATH_SRCS), $(PATH_OBJS), $(SRCS)))

LIBFT = $(PATH_LIBFT)/libft.a

all:$(BIN)

$(BIN): $(OBJS) | $(LIBFT)
		@$(CC) $(CFLAGS) $(LBX_FLAGS) -o $(@) $^ -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDES)
		@echo "\033[33m[Moving Images]\033[0m"
		@mv ./images/*.xpm ./

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c | $(PATH_BUILD)
		@echo "\033[33m[CREATING ${@F}]\033[0m"
		@$(CC) $(CFLAGS) -c $(^) -o $@

$(LIBFT):
		@make -C $(PATH_LIBFT)

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS)

clean:
		@echo "\033[38;5;1m[REMOVING OBJECTS]\033[0m"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@echo "\033[38;5;1m[REMOVING BINARIES]\033[0m"
		@rm -rf $(PATH_BUILD) $(NAME)
		@make fclean -C $(PATH_LIBFT)
		@mv ./*.xpm ./images/

exe: all
		@./$(NAME) test.ber

re: fclean all

.PHONY: all exe