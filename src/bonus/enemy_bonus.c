/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:25 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/30 15:01:05 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_step(t_gamesettings *game)
{
	t_position	*tmp;
	t_position	*tinfo;

	tmp = game->enemy;
	while (tmp != NULL)
	{
		if (tmp->espeed == ENEMY_SPEED)
		{
			tinfo = get_position(game, tmp->x + (tmp->sign * 32), tmp->y);
			if (tinfo != NULL && (tinfo->type == 'E' || tinfo->type == '1'\
			|| tinfo->type == 'C'))
				tmp->sign *= -1;
			if (tinfo != NULL && tinfo->type == 'P')
				print_lose_message(game);
			tinfo = get_position(game, tmp->x + tmp->sign * 32, tmp->y);
			if (tinfo != NULL && tinfo->type != '1' && tinfo->type != 'E'\
			&& tinfo->type != 'C')
				tmp->x += tmp->sign * 32;
			tmp->espeed = 0;
		}
		tmp->espeed++;
		tmp = tmp->next;
	}
}

void	enemy_move(t_gamesettings *game)
{
	char		*img[7];
	t_position	*tmp;

	img[0] = game->image.enemy_1;
	img[1] = game->image.enemy_2;
	img[2] = game->image.enemy_3;
	img[3] = game->image.enemy_4;
	img[4] = game->image.enemy_5;
	img[5] = game->image.enemy_6;
	img[6] = game->image.enemy_7;
	tmp = game->enemy;
	while (tmp != NULL)
	{
		if (tmp->espeed % 5 == 0)
		{
			if (tmp->png_index == ENEMY_MAX)
				tmp->png_index = 0;
			tmp->png = img[tmp->png_index];
			tmp->png_index += 1;
		}
		tmp = tmp->next;
	}
	draw_image(game, game->enemy);
}
