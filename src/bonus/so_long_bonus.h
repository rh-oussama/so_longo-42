/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:52:45 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/18 15:40:23 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <mlx.h>
# include "../../pgnl/get_next_line.h"

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307
# define ENEMY_SPEED 10
# define COIN_SPEED 5
# define PLAYER_SPEED 5
# define COIN_MAX 5
# define PLAYER_MAX 6
# define ENEMY_MAX 7

typedef struct s_position
{
	char					*png;
	int						x;
	int						y;
	int						state;
	int						png_index;
	char					type;
	int						espeed;
	int						sign;
	struct s_position		*next;
}	t_position;

typedef struct s_image
{
	char	*wall;
	char	*background;
	char	*tresure;
	char	*tresure02;
	char	*player_1;
	char	*player_2;
	char	*player_3;
	char	*player_4;
	char	*player_5;
	char	*player_6;
	char	*player_1_l;
	char	*player_2_l;
	char	*player_3_l;
	char	*player_4_l;
	char	*player_5_l;
	char	*player_6_l;
	char	*coin_1;
	char	*coin_2;
	char	*coin_3;
	char	*coin_4;
	char	*coin_5;
	char	*enemy_1;
	char	*enemy_2;
	char	*enemy_3;
	char	*enemy_4;
	char	*enemy_5;
	char	*enemy_6;
	char	*enemy_7;
	char	*number_0;
	char	*number_1;
	char	*number_2;
	char	*number_3;
	char	*number_4;
	char	*number_5;
	char	*number_6;
	char	*number_7;
	char	*number_8;
	char	*number_9;
}	t_image;

typedef struct s_gamewindow
{
	char	*init_ptr;
	char	*window_ptr;
}	t_gamewindow;

typedef struct s_gamemap
{
	int	width;
	int	height;
}	t_gamemap;

typedef struct s_gamesettings
{
	int				status;
	int				move;
	int				key_left;
	int				door_open_close;
	int				right_left;
	char			**game_map;
	t_gamemap		map;
	t_gamewindow	window;
	t_image			image;
	t_position		*player;
	t_position		*exit_door;
	t_position		*coin;
	t_position		*wall;
	t_position		*background;
	t_position		*enemy;
}	t_gamesettings;

//////////// CHECK MAP VALIDITY ///////////////////

typedef struct s_node
{
	int				x;
	int				y;
	char			visited_block;
	struct s_node	*next;
}	t_back_track;

typedef struct s_mapinfo
{
	int		x_max;
	int		y_max;
	int		player;
	int		x_player;
	int		y_player;
	int		exit;
	int		y;
	int		x;
	int		total_coin;
	char	current_char;
}	t_mapinfo;

///// CHECK MAP DEMINSIION AND CHECK PLAYER MOVE 

void		backtrack(char ***map_visited, int x, int y, t_back_track **player);
void		backtrack_coin(char ***map_visited, int x, int y, \
t_back_track **player);
t_mapinfo	initialize_map_info(char **map);
int			check_map_dimension(char **map, t_mapinfo info);
int			check_position(char **map, t_mapinfo info);
void		check_map(char **map);
void		get_coin_player(char **map, t_mapinfo *info);
int			get_total_visited(t_back_track *tmp, char c);

///// FREE GAME ASSESTS

void		free_double_pointer(char **arr);
void		free_back_track(t_back_track *player);
void		free_positions(t_position *param);
void		destroy_all_image(t_gamesettings *game);
void		free_all_game(t_gamesettings *game);

///// READ MAP and LOAD POSITIONS 

char		**read_map(char *maps);
t_position	*ft_lstlast(t_position *lst);
void		ft_lstadd_back(t_position **lst, t_position *new);
void		fill_map_deminssion(t_gamesettings *game, char **map);
t_position	*creat_deplucate(t_position *game, char c);
void		handle_type(t_gamesettings *game, t_position *blo, char c);
void		fill_cor(t_gamesettings *game, char **map);

////// LOAD IMAGE AND INIT THE PARAM

void		init_game_param(t_gamesettings *game, char **map);
void		load_coin(t_gamesettings	*game);
void		load_player(t_gamesettings	*game);
void		load_assests(t_gamesettings *game);

///// UPDATE PARAM AND DRAW

t_position	*get_position(t_gamesettings *game, int x, int y);
void		update_key_left(t_gamesettings *game);
void		draw_image(t_gamesettings *game, t_position *lst);
int			render(t_gamesettings *game);
int			can_move(t_gamesettings *game, int x, int y);
int			handle_key_press(int keycode, void *param);
int			close_window(void *param);

//// 

char		**creat_dfs_map(t_mapinfo info);
void		coin_flip(t_gamesettings *game);
void		player_move(t_gamesettings *game);

//////

char		*get_number_image(int number, t_gamesettings *game);
void		build_backround(t_gamesettings *game);
void		draw_number(t_gamesettings *game, int number, int pos);
void		print_step(t_gamesettings *game, int number);
void		enemy_move(t_gamesettings *game);
void		enemy_step(t_gamesettings *game);
void		print_lose_message(t_gamesettings *game);
void		print_win_message(t_gamesettings *game);
void		argv_checker(int argc, char **argv);

#endif