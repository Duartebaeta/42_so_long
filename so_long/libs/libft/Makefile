NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.c ft_atoi.c ft_strjoin.c \
	   ft_strncmp.c ft_split.c ft_strtrim.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_strdup.c \
	   ft_tolower.c ft_toupper.c ft_substr.c \
	   ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_memset.c ft_calloc.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_bzero.c ft_strnstr.c \
	   ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	   	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_chbase.c ft_printf_c.c ft_printf_di.c ft_printf_p.c \
		ft_printf_s.c ft_printf_u.c ft_printf_x.c ft_printf.c \
		temp_gnl.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
INCLUDES = libft.h


.c.o:
		@$(CC) $(CFLAGS) -c $(SRCS) 

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		@$(RM) $(OBJS) 

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 