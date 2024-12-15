/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:25:27 by oussama           #+#    #+#             */
/*   Updated: 2024/02/21 21:30:18 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render(t_gamesettings *game)
{
	update_key_left(game);
	draw_image(game, game->background);
	draw_image(game, game->wall);
	player_move(game);
	enemy_move(game);
	enemy_step(game);
	coin_flip(game);
	print_step(game, game->move);
	draw_image(game, game->exit_door);
	usleep(10000);
	return (0);
}

int	can_move(t_gamesettings *game, int x, int y)
{
	t_position	*tmp;

	tmp = get_position(game, x, y);
	if (tmp == NULL)
		return (0);
	if (tmp->type == '1')
		return (0);
	else if (tmp->type == 'C')
		tmp->state = 0;
	else if (tmp->type == 'E')
	{
		if (game->door_open_close == 0)
			print_win_message(game);
		return (0);
	}
	else if (tmp->type == 'X')
	{
		print_lose_message(game);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char			**list;
	t_gamesettings	*game;

	argv_checker(argc, argv);
	list = read_map(argv[1]);
	if (!list)
	{
		ft_printf("Error: The map is invalid.\n");
		exit(EXIT_FAILURE);
	}
	check_map(list);
	game = malloc(sizeof(t_gamesettings));
	if (!game)
		return (0);
	game->game_map = list;
	init_game_param(game, list);
	fill_cor(game, list);
	mlx_key_hook(game->window.window_ptr, handle_key_press, game);
	mlx_hook(game->window.window_ptr, 17, 0, close_window, game);
	mlx_loop_hook(game->window.init_ptr, render, game);
	mlx_loop(game->window.init_ptr);
}
