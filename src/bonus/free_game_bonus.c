/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:19:20 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/29 20:48:03 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_double_pointer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
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
	mlx_destroy_image(game->window.init_ptr, game->image.coin_2);
	mlx_destroy_image(game->window.init_ptr, game->image.coin_3);
	mlx_destroy_image(game->window.init_ptr, game->image.coin_4);
	mlx_destroy_image(game->window.init_ptr, game->image.coin_5);
	mlx_destroy_image(game->window.init_ptr, game->image.player_1);
	mlx_destroy_image(game->window.init_ptr, game->image.player_2);
	mlx_destroy_image(game->window.init_ptr, game->image.player_3);
	mlx_destroy_image(game->window.init_ptr, game->image.player_4);
	mlx_destroy_image(game->window.init_ptr, game->image.player_5);
	mlx_destroy_image(game->window.init_ptr, game->image.player_6);
	mlx_destroy_image(game->window.init_ptr, game->image.player_1_l);
	mlx_destroy_image(game->window.init_ptr, game->image.player_2_l);
	mlx_destroy_image(game->window.init_ptr, game->image.player_3_l);
	mlx_destroy_image(game->window.init_ptr, game->image.player_4_l);
	mlx_destroy_image(game->window.init_ptr, game->image.player_5_l);
	mlx_destroy_image(game->window.init_ptr, game->image.player_6_l);
	mlx_destroy_image(game->window.init_ptr, game->image.number_8);
	mlx_destroy_image(game->window.init_ptr, game->image.number_9);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_1);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_2);
}

void	free_all_game(t_gamesettings *game)
{
	free_positions(game->player);
	free_positions(game->exit_door);
	free_positions(game->coin);
	free_positions(game->wall);
	free_positions(game->background);
	free_positions(game->enemy);
	destroy_all_image(game);
	mlx_destroy_image(game->window.init_ptr, game->image.number_0);
	mlx_destroy_image(game->window.init_ptr, game->image.number_1);
	mlx_destroy_image(game->window.init_ptr, game->image.number_2);
	mlx_destroy_image(game->window.init_ptr, game->image.number_3);
	mlx_destroy_image(game->window.init_ptr, game->image.number_4);
	mlx_destroy_image(game->window.init_ptr, game->image.number_5);
	mlx_destroy_image(game->window.init_ptr, game->image.number_6);
	mlx_destroy_image(game->window.init_ptr, game->image.number_7);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_3);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_4);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_5);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_6);
	mlx_destroy_image(game->window.init_ptr, game->image.enemy_7);
	mlx_destroy_window(game->window.init_ptr, game->window.window_ptr);
	mlx_destroy_display(game->window.init_ptr);
	free(game->window.init_ptr);
	free_double_pointer(game->game_map);
	free(game);
}
