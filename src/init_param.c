/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:49:10 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/21 21:21:47 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map_deminssion(t_gamesettings *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map && map[y] != NULL)
	{
		x = 0;
		while (map && map[y][x] != '\0')
			x++;
		y++;
	}
	game->map.width = x * 32;
	game->map.height = y * 32;
}

t_position	*creat_deplucate(t_position *game, char c)
{
	t_position	*tmp;

	tmp = malloc(sizeof(t_position));
	if (!tmp)
		return (NULL);
	tmp->x = game->x;
	tmp->y = game->y;
	tmp->type = c;
	tmp->state = 1;
	tmp->next = NULL;
	return (tmp);
}

void	assign_and_add(t_gamesettings *game, t_position **list, \
t_position *blo, char *img)
{
	t_position	*tmp;

	if (img != game->image.background)
	{
		tmp = creat_deplucate(blo, '0');
		tmp->png = game->image.background;
		ft_lstadd_back(&(game->background), tmp);
	}
	blo->png = img;
	ft_lstadd_back(list, blo);
}

void	handle_type(t_gamesettings *game, t_position *blo, char c)
{
	if (c == '1')
		assign_and_add(game, &(game->wall), blo, game->image.wall);
	else if (c == '0')
		assign_and_add(game, &(game->background), blo, game->image.background);
	else if (c == 'P')
		assign_and_add(game, &(game->player), blo, game->image.player_1);
	else if (c == 'C')
		assign_and_add(game, &(game->coin), blo, game->image.coin_1);
	else if (c == 'E')
		assign_and_add(game, &(game->exit_door), blo, game->image.tresure);
	else
		exit(EXIT_FAILURE);
}

void	fill_cor(t_gamesettings *game, char **map)
{
	int			i;
	int			y;
	t_position	*tmp;

	y = 0;
	while (map && map[y] != NULL)
	{
		i = 0;
		while (map && map[y][i] != '\0')
		{
			tmp = malloc(sizeof(t_position));
			if (!tmp)
				return (NULL);
			tmp->x = i * 32;
			tmp->y = y * 32;
			tmp->type = map[y][i];
			tmp->state = 1;
			tmp->png_index = 0;
			tmp->next = NULL;
			handle_type(game, tmp, map[y][i]);
			i++;
		}
		y++;
	}
}
