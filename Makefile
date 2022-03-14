NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
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
		$(PATH_SRCS)/custom_error.c

OBJS := $(subst .c,.o,$(subst $(PATH_SRCS), $(PATH_OBJS), $(SRCS)))

LIBFT = $(PATH_LIBFT)/libft.a

all:$(BIN)

$(BIN): $(OBJS) | $(LIBFT)
		@$(CC) $(CFLAGS) $(LBX_FLAGS) -o $(@) $^ -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDES)

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c | $(PATH_BUILD)
		@printf "\033[33m[CREATING ${@F}]\033[0m\n"
		@$(CC) $(CFLAGS) -c $(^) -o $@

$(LIBFT):
		@make -C $(PATH_LIBFT)

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS)

clean:
		@printf "\033[38;5;1m[REMOVING OBJECTS]\033[0m\n"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@printf "\033[38;5;1m[REMOVING BINARIES]\033[0m\n"
		@rm -rf $(PATH_BUILD) $(NAME)
		@make fclean -C $(PATH_LIBFT)

re: fclean all