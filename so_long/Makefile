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
PATH_IMAGES := ./images

BIN := ./$(NAME)
SRCS := $(PATH_SRCS)/main.c \
		$(PATH_SRCS)/read_map.c \
		$(PATH_SRCS)/check_map.c \
		$(PATH_SRCS)/custom_error.c \
		$(PATH_SRCS)/init.c \
		$(PATH_SRCS)/utils.c \
		$(PATH_SRCS)/moves.c

OBJS := $(subst .c,.o,$(subst $(PATH_SRCS), $(PATH_OBJS), $(SRCS)))

IMAGES := Enemy_front.xpm \
		grass_1.xpm \
		key.xpm \
		Male_down.xpm \
		Male_left.xpm \
		Male_right.xpm \
		Male_up.xpm \
		portal_stable.xpm \
		portal.xpm \
		tree.xpm \
		water_1.xpm

LIBFT = $(PATH_LIBFT)/libft.a

all:$(BIN)

$(BIN): $(OBJS) | $(LIBFT) $(IMAGES)
		@$(CC) $(CFLAGS) $(LBX_FLAGS) -o $(@) $^ -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDES)
		@echo "\033[33m[Moving Images]\033[0m"

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c | $(PATH_BUILD)
		@echo "\033[33m[CREATING ${@F}]\033[0m"
		@$(CC) $(CFLAGS) -c $(^) -o $@

$(LIBFT):
		@make -C $(PATH_LIBFT)

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS)

$(IMAGES):
		@mv $(PATH_IMAGES)/*.xpm ./

clean:
		@echo "\033[38;5;1m[REMOVING OBJECTS]\033[0m"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@echo "\033[38;5;1m[REMOVING BINARIES]\033[0m"
		@rm -rf $(PATH_BUILD) $(NAME)
		@make fclean -C $(PATH_LIBFT)
		@mv ./*.xpm $(PATH_IMAGES)/

exe: all
		@./$(NAME) map.ber

re: fclean all

.PHONY: all exe