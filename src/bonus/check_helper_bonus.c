/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:50:24 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/21 21:23:05 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_coin_player(char **map, t_mapinfo *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < info->y_max)
	{
		x = 0;
		while (x < info->x_max)
		{
			if (map && map[y][x] == 'C')
				info->total_coin++;
			if (map && map[y][x] == 'P')
			{
				info->x_player = x;
				info->y_player = y;
			}
			x++;
		}
		y++;
	}
}

int	get_total_visited(t_back_track *tmp, char c)
{
	int	total;

	total = 0;
	while (tmp != NULL)
	{
		if (tmp->visited_block == c)
			total++;
		tmp = tmp->next;
	}
	return (total);
}

char	**creat_dfs_map(t_mapinfo info)
{
	int				i;
	int				j;
	char			**visited;

	i = 0;
	j = 0;
	visited = malloc((info.y_max + 1) * sizeof(char *));
	if (!visited)
		return (NULL);
	while (i < info.y_max)
	{
		visited[i] = malloc(info.x_max * sizeof(char));
		if (!visited[i])
			return (NULL);
		j = 0;
		while (j < info.x_max)
			visited[i][j++] = 'F';
		i++;
	}
	visited[info.y_max] = NULL;
	return (visited);
}

void	init_game_param(t_gamesettings *game, char **map)
{
	fill_map_deminssion(game, map);
	game->door_open_close = 1;
	game->right_left = 1;
	game->move = 0;
	game->status = 1;
	game->window.init_ptr = NULL;
	game->window.window_ptr = NULL;
	game->image.wall = NULL;
	game->image.background = NULL;
	game->image.player_1 = NULL;
	game->player = NULL;
	game->exit_door = NULL;
	game->coin = NULL;
	game->wall = NULL;
	game->background = NULL;
	load_assests(game);
}

void	backtrack_coin(char ***map_visited, int x, int y, t_back_track **player)
{
	t_back_track	*new_node;

	if (x < 0 || y < 0 || map_visited[0][y][x] == 'E' || \
	map_visited[0][y][x] == 'X' || map_visited[0][y][x] == '1' \
	|| map_visited[1][y][x] == 'T')
		return ;
	new_node = malloc(sizeof(t_back_track));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->visited_block = map_visited[0][y][x];
	new_node->next = *player;
	*player = new_node;
	map_visited[1][y][x] = 'T';
	backtrack_coin(map_visited, x, y - 1, player);
	backtrack_coin(map_visited, x, y + 1, player);
	backtrack_coin(map_visited, x - 1, y, player);
	backtrack_coin(map_visited, x + 1, y, player);
}
