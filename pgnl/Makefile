NAME = pgnl.a

FILES = ft_split.c get_next_line.c get_next_line_utils.c \
          ft_printf.c ft_printf_utils_2.c \
          ft_printf_utils.c ft_strdup.c

OBJS = $(FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)