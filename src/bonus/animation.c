/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:27:23 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/29 21:25:30 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_flip(t_gamesettings *game)
{
	char		*img[5];
	t_position	*tmp;

	img[0] = game->image.coin_1;
	img[1] = game->image.coin_2;
	img[2] = game->image.coin_3;
	img[3] = game->image.coin_4;
	img[4] = game->image.coin_5;
	tmp = game->coin;
	while (tmp != NULL)
	{
		if (tmp->espeed == COIN_SPEED)
		{
			if (tmp->png_index == COIN_MAX)
				tmp->png_index = 0;
			tmp->png = img[tmp->png_index];
			tmp->png_index += 1;
			tmp->espeed = 0;
		}
		tmp->espeed++;
		tmp = tmp->next;
	}
	draw_image(game, game->coin);
}

void	player_move_right(t_gamesettings *game)
{
	char		*img[6];
	t_position	*tmp;

	img[0] = game->image.player_1;
	img[1] = game->image.player_2;
	img[2] = game->image.player_3;
	img[3] = game->image.player_4;
	img[4] = game->image.player_5;
	img[5] = game->image.player_6;
	tmp = game->player;
	while (tmp != NULL)
	{
		if (tmp->espeed == COIN_SPEED)
		{
			if (tmp->png_index == PLAYER_MAX)
				tmp->png_index = 0;
			tmp->png = img[tmp->png_index];
			tmp->png_index += 1;
			tmp->espeed = 0;
		}
		tmp->espeed++;
		tmp = tmp->next;
	}
	draw_image(game, game->player);
}

void	player_move_left(t_gamesettings *game)
{
	char		*img[6];
	t_position	*tmp;

	img[0] = game->image.player_1_l;
	img[1] = game->image.player_2_l;
	img[2] = game->image.player_3_l;
	img[3] = game->image.player_4_l;
	img[4] = game->image.player_5_l;
	img[5] = game->image.player_6_l;
	tmp = game->player;
	while (tmp != NULL)
	{
		if (tmp->espeed == COIN_SPEED)
		{
			if (tmp->png_index == PLAYER_MAX)
				tmp->png_index = 0;
			tmp->png = img[tmp->png_index];
			tmp->png_index += 1;
			tmp->espeed = 0;
		}
		tmp->espeed++;
		tmp = tmp->next;
	}
	draw_image(game, game->player);
}

void	player_move(t_gamesettings *game)
{
	if (game->right_left == 1)
		player_move_right(game);
	if (game->right_left == 0)
		player_move_left(game);
}
