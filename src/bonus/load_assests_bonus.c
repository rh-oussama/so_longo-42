/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:41:09 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/29 20:50:14 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_gamesettings	*game)
{
	int	tmp;

	game->image.enemy_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/1.xpm", &tmp, &tmp);
	game->image.enemy_2 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/2.xpm", &tmp, &tmp);
	game->image.enemy_3 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/3.xpm", &tmp, &tmp);
	game->image.enemy_4 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/4.xpm", &tmp, &tmp);
	game->image.enemy_5 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/5.xpm", &tmp, &tmp);
	game->image.enemy_6 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/6.xpm", &tmp, &tmp);
	game->image.enemy_7 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/enemy/7.xpm", &tmp, &tmp);
}

void	load_number(t_gamesettings	*game)
{
	int	tmp;

	game->image.number_0 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/0.xpm", &tmp, &tmp);
	game->image.number_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/1.xpm", &tmp, &tmp);
	game->image.number_2 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/2.xpm", &tmp, &tmp);
	game->image.number_3 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/3.xpm", &tmp, &tmp);
	game->image.number_4 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/4.xpm", &tmp, &tmp);
	game->image.number_5 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/5.xpm", &tmp, &tmp);
	game->image.number_6 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/6.xpm", &tmp, &tmp);
	game->image.number_7 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/7.xpm", &tmp, &tmp);
	game->image.number_8 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/8.xpm", &tmp, &tmp);
	game->image.number_9 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/number/9.xpm", &tmp, &tmp);
}

void	load_coin(t_gamesettings	*game)
{
	int	tmp;

	game->image.coin_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/1.xpm", &tmp, &tmp);
	game->image.coin_2 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/2.xpm", &tmp, &tmp);
	game->image.coin_3 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/3.xpm", &tmp, &tmp);
	game->image.coin_4 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/4.xpm", &tmp, &tmp);
	game->image.coin_5 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/5.xpm", &tmp, &tmp);
	game->image.player_6_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/6.xpm", &tmp, &tmp);
}

void	load_player(t_gamesettings	*game)
{
	int	tmp;

	game->image.player_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/1.xpm", &tmp, &tmp);
	game->image.player_2 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/2.xpm", &tmp, &tmp);
	game->image.player_3 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/3.xpm", &tmp, &tmp);
	game->image.player_4 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/4.xpm", &tmp, &tmp);
	game->image.player_5 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/5.xpm", &tmp, &tmp);
	game->image.player_6 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/6.xpm", &tmp, &tmp);
	game->image.player_1_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/1.xpm", &tmp, &tmp);
	game->image.player_2_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/2.xpm", &tmp, &tmp);
	game->image.player_3_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/3.xpm", &tmp, &tmp);
	game->image.player_4_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/4.xpm", &tmp, &tmp);
	game->image.player_5_l = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/left/5.xpm", &tmp, &tmp);
}

void	load_assests(t_gamesettings *game)
{
	int	tmp;

	game->window.init_ptr = mlx_init();
	game->window.window_ptr = mlx_new_window(game->window.init_ptr, \
	game->map.width, game->map.height + 32, "So Long");
	game->image.background = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/wall/floor.xpm", &tmp, &tmp);
	game->image.wall = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/wall/wall.xpm", &tmp, &tmp);
	game->image.tresure = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/door/tresure01.xpm", &tmp, &tmp);
	game->image.tresure02 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/door/tresure02.xpm", &tmp, &tmp);
	load_player(game);
	load_coin(game);
	load_enemy(game);
	load_number(game);
}
