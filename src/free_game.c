/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:19:20 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/21 21:15:05 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_back_track(t_back_track *player)
{
	t_back_track	*tmp;

	while (player != NULL)
	{
		tmp = player->next;
		free(player);
		player = tmp;
	}
}

void	free_positions(t_position *param)
{
	t_position	*tmp;

	while (param != NULL)
	{
		tmp = param->next;
		free(param);
		param = tmp;
	}
}

void	destroy_all_image(t_gamesettings *game)
{
	mlx_destroy_image(game->window.init_ptr, game->image.wall);
	mlx_destroy_image(game->window.init_ptr, game->image.background);
	mlx_destroy_image(game->window.init_ptr, game->image.tresure);
	mlx_destroy_image(game->window.init_ptr, game->image.tresure02);
	mlx_destroy_image(game->window.init_ptr, game->image.coin_1);
	mlx_destroy_image(game->window.init_ptr, game->image.player_1);
}

void	free_all_game(t_gamesettings *game)
{
	free_positions(game->player);
	free_positions(game->exit_door);
	free_positions(game->coin);
	free_positions(game->wall);
	free_positions(game->background);
	destroy_all_image(game);
	mlx_destroy_window(game->window.init_ptr, game->window.window_ptr);
	mlx_destroy_display(game->window.init_ptr);
	free(game->window.init_ptr);
	free_double_pointer(game->game_map);
	free(game);
}
