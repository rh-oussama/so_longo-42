NAME = so_long
NAME_B = so_long_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lXext -lX11
LIB = pgnl/pgnl.a
FILES = src/load_assests.c src/check_movement.c src/init_param.c src/so_long.c src/read_tool.c \
        src/check_helper.c src/free_game.c src/so_long_helper.c src/argv_checker.c

FILES_B = src/bonus/check_movement_bonus.c src/bonus/so_long_helper_bonus.c \
          src/bonus/check_helper_bonus.c src/bonus/init_param_bonus.c src/bonus/read_tool.c \
          src/bonus/so_long_bonus.c src/bonus/animation.c src/bonus/free_game_bonus.c \
          src/bonus/load_assests_bonus.c src/bonus/move_counter_bonus.c src/bonus/enemy_bonus.c\
          src/bonus/messages_bonus.c src/argv_checker.c

all: $(NAME)
bonus: $(NAME_B)

$(LIB):
	@make -s -C pgnl

$(NAME): $(FILES) $(LIB)
	$(CC) $(FILES) $(LIB) $(FLAGS) -o $(NAME)

$(NAME_B): $(FILES_B) $(LIB) 
	$(CC) $(FILES_B) $(LIB) $(FLAGS) -o $(NAME_B)

clean:
	@make -s -C pgnl fclean

fclean: clean
	@rm -rf $(NAME) $(NAME_B)

re: fclean all bonus