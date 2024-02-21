/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:35:46 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/29 21:07:44 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_number_image(int number, t_gamesettings *game)
{
	char	*img[10];

	img[0] = game->image.number_0;
	img[1] = game->image.number_1;
	img[2] = game->image.number_2;
	img[3] = game->image.number_3;
	img[4] = game->image.number_4;
	img[5] = game->image.number_5;
	img[6] = game->image.number_6;
	img[7] = game->image.number_7;
	img[8] = game->image.number_8;
	img[9] = game->image.number_9;
	return (img[number]);
}

void	build_backround(t_gamesettings *game)
{
	int			x;
	int			y;

	x = 0;
	y = game->map.height;
	while (x < game->map.width)
	{
		mlx_put_image_to_window(game->window.init_ptr, \
			game->window.window_ptr, game->image.background, x, y);
		x += 32;
	}
}

void	draw_number(t_gamesettings *game, int number, int pos)
{
	int	x;
	int	y;

	x = pos * 32;
	y = game->map.height;
	mlx_put_image_to_window(game->window.init_ptr, \
		game->window.window_ptr, get_number_image(number, game), x, y);
}

void	print_step(t_gamesettings *game, int number)
{
	int	num_len;
	int	temp;
	int	digit;
	int	position;

	build_backround(game);
	num_len = 0;
	temp = number;
	position = ((game->map.width / 32) / 2) + 1;
	if (number == 0)
		draw_number(game, 0, position);
	while (temp != 0)
	{
		num_len++;
		temp /= 10;
	}
	while (number > 0)
	{
		digit = number % 10;
		draw_number(game, digit, position);
		number /= 10;
		position--;
	}
}
