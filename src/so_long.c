/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:25:27 by oussama           #+#    #+#             */
/*   Updated: 2024/02/21 21:29:37 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_gamesettings *game)
{
	update_key_left(game);
	if (game->speed == 0)
	{
		draw_image(game, game->background);
		draw_image(game, game->wall);
		draw_image(game, game->coin);
		draw_image(game, game->player);
		draw_image(game, game->exit_door);
		(game->speed)++;
	}
	(game->speed)++;
	if (game->speed == 5000)
		game->speed = 0;
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
		{
			print_win_message();
			free_all_game(game);
			exit(0);
		}
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
	game->speed = 0;
	init_game_param(game, list);
	fill_cor(game, list);
	mlx_key_hook(game->window.window_ptr, handle_key_press, game);
	mlx_hook(game->window.window_ptr, 17, 0, close_window, game);
	mlx_loop_hook(game->window.init_ptr, render, game);
	mlx_loop(game->window.init_ptr);
}
