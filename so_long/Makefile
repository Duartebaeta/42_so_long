### OPERATING SYSTEM ###
OS			:=	$(shell uname -s)

### EXECUTABLE ###
NAME		:=	cub3d

### COMPILATION ###
CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra -g

### PATHS ###
LIBFT_PATH	:=	./libs/libft/
INCL_PATH	:=	includes/
SRCS_PATH	:=	srcs/
OBJS_PATH	:=	obj/
ifeq ($(OS), Linux)
	MLX_PATH:=	./minilibx-linux/
else
	MLX_PATH:=	./minilibx_macos/
endif

### SOURCE FILES ###
SRC_NAME	:=	main.c
#SRC_BONUS=	$(NAME)_bonus.c
SRCS		:=	check_map.c \
				custom_error.c \
				init.c \
				moves.c \
				read_map.c \
				utils.c
SRCS_NAME	:=	$(addprefix $(SRCS_PATH), $(SRC_NAME) $(SRCS))
#SRCS_BONUS=	$(addprefix $(SRCS_PATH), $(SRC_BONUS) $(SRCS))

### OBJECT FILES ###
OBJ_NAME	:=	$(SRC_NAME:.c=.o)
#OBJ_BONUS	:=	$(SRC_BONUS:.c=.o)
OBJS		:=	$(SRCS:.c=.o)
OBJS_NAME	:=	$(addprefix $(OBJS_PATH), $(OBJ_NAME) $(OBJS))
#OBJS_BONUS	:=	$(addprefix $(OBJS_PATH), $(OBJ_BONUS) $(OBJS))

### LIBFT ###
LIBFTMAKE	:=	make --silent -C $(LIBFT_PATH)
LIBFT		:=	-L$(LIBFT_PATH) -lft

### MLXLIB ###
MLXMAKE		:=	make --silent -C $(MLX_PATH)
ifeq ($(OS), Linux)
	MLX		:=	-L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm -lz -O3
else
	MLX		:=	-L$(MLX_PATH) -lmlx -lm -framework OpenGL -framework AppKit -O3
endif

### INCLUDES ###
INC			:=	-I $(LIBFT_PATH)$(INCL_PATH) -I $(INCL_PATH) -I $(MLX_PATH)

PATH_IMAGES := ./images
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

### COLOURS ###
ifeq ($(OS), Linux)
	ECHO	:=	echo "
else
	ECHO	:=	echo "
endif
GREEN= $(addprefix $(ECHO), \033[1;32m)
RED= $(addprefix $(ECHO), \033[1;31m)
DEFAULT= \033[0m"

### IMPLICT RULES ###
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

### ACTIVE RULES ###
all: $(NAME) ## compiles cub3d with mandatory requirements

$(NAME): $(OBJS_PATH) $(OBJS_NAME) $(IMAGES)
	@$(LIBFTMAKE)
	@$(MLXMAKE)
	@$(CC) $(CFLAGS) $(OBJS_NAME) $(INC) $(LIBFT) $(MLX) -o $(NAME)
	@$(GREEN)$(NAME) Program created$(DEFAULT)

$(OBJS_PATH):
	@mkdir -p $@

$(IMAGES):
		@mv $(PATH_IMAGES)/*.xpm ./

clean: ## removes object files
	@make $@ --silent -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@$(RED)Object files removed$(DEFAULT)

fclean: clean ## removes object files and binary
	@make $@ --silent -C $(LIBFT_PATH)
	@$(RED)Libft removed$(DEFAULT)
	@rm -f $(NAME)
	@$(RED)$(NAME) Program removed$(DEFAULT)
	@mv ./*.xpm $(PATH_IMAGES)/

re: fclean all ## recompiles cub3d

### NORMINETTE ###
norm: ## checks norminette requirements
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH)
	@norminette -R CheckForbiddenSourceHeader $(INCL_PATH)
	@norminette -R CheckDefine $(SRCS_PATH)
	@norminette -R CheckDefine $(INCL_PATH)

### HELP ###
help:  ## show this help
	@echo "usage: make [target]"
	@echo ""
	@egrep "^(.+)\:\ .*##\ (.+)" ${MAKEFILE_LIST} | sed 's/:.*##/#/' | column -t -c 2 -s '#'

### PHONY RULE ###
.PHONY:	all help bonus clean fclean re norm
