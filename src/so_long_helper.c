/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:02:53 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/18 11:30:58 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	free_all_game((t_gamesettings *) param);
	exit(0);
}

void	draw_image(t_gamesettings *game, t_position *lst)
{
	t_position	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->state == 1)
			mlx_put_image_to_window(game->window.init_ptr, \
			game->window.window_ptr, tmp->png, tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

void	update_direction(int keycode, t_gamesettings *game, int *dx, int *dy)
{
	if (keycode == KEY_W)
		*dy = -32;
	else if (keycode == KEY_D)
	{
		game->right_left = 1;
		*dx = 32;
	}
	else if (keycode == KEY_S)
		*dy = 32;
	else if (keycode == KEY_A)
	{
		game->right_left = 0;
		*dx = -32;
	}
}

int	handle_key_press(int keycode, void *param)
{
	t_gamesettings	*game;
	int				dx;
	int				dy;

	if (keycode != KEY_A && keycode != KEY_D && keycode != KEY_S && \
				keycode != KEY_W && keycode != KEY_ESC)
		return (0);
	game = (t_gamesettings *) param;
	dx = 0;
	dy = 0;
	if (keycode == KEY_ESC)
		close_window(param);
	update_direction(keycode, game, &dx, &dy);
	if (can_move(game, game->player->x + dx, game->player->y + dy) == 1)
	{
		update_key_left(game);
		game->player->x += dx;
		game->player->y += dy;
		game->move++;
		ft_printf("player move > %d\n", game->move);
	}
	return (0);
}
