/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:18:48 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/18 11:35:22 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assests(t_gamesettings *game)
{
	int	tmp;

	game->window.init_ptr = mlx_init();
	game->window.window_ptr = mlx_new_window(game->window.init_ptr, \
	game->map.width, game->map.height, "So Long");
	game->image.background = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/wall/floor.xpm", &tmp, &tmp);
	game->image.wall = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/wall/wall.xpm", &tmp, &tmp);
	game->image.tresure = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/door/tresure01.xpm", &tmp, &tmp);
	game->image.tresure02 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/door/tresure02.xpm", &tmp, &tmp);
	game->image.player_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/player/right/1.xpm", &tmp, &tmp);
	game->image.coin_1 = mlx_xpm_file_to_image(game->window.init_ptr, \
	"assests/coin/1.xpm", &tmp, &tmp);
}

void	print_win_message(void)
{
	ft_printf("\n");
	ft_printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗\
██╗███╗   ██╗    ██╗\n");
	ft_printf("╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║\
██║████╗  ██║    ██║\n");
	ft_printf(" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║\
██║██╔██╗ ██║    ██║\n");
	ft_printf("  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║\
██║██║╚██╗██║    ╚═╝\n");
	ft_printf("   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝\
██║██║ ╚████║    ██╗\n");
	ft_printf("   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ \
╚═╝╚═╝  ╚═══╝    ╚═╝\n");
	ft_printf("\n");
}
