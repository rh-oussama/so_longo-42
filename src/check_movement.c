/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:17:33 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/21 21:21:06 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	backtrack(char ***map_visited, int x, int y, t_back_track **player)
{
	t_back_track	*new_node;

	if (x < 0 || y < 0 || map_visited[0][y][x] == '1' \
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
	backtrack(map_visited, x, y - 1, player);
	backtrack(map_visited, x, y + 1, player);
	backtrack(map_visited, x - 1, y, player);
	backtrack(map_visited, x + 1, y, player);
}

t_mapinfo	initialize_map_info(char **map)
{
	t_mapinfo	map_info;

	map_info.x_max = ft_strlen(map[0]);
	map_info.y_max = 0;
	map_info.player = 0;
	map_info.exit = 0;
	map_info.y = 0;
	map_info.x = 0;
	map_info.total_coin = 0;
	map_info.x_player = 0;
	map_info.y_player = 0;
	while (map[map_info.y_max] != NULL)
		map_info.y_max++;
	get_coin_player(map, &map_info);
	return (map_info);
}

int	check_map_dimension(char **map, t_mapinfo info)
{
	while (info.y < info.y_max)
	{
		if (ft_strlen(map[info.y]) != (size_t) info.x_max)
			return (1);
		info.x = 0;
		while (info.x < info.x_max)
		{
			info.current_char = map[info.y][info.x];
			if ((info.y == 0 || info.y == info.y_max - 1 || info.x == 0 \
			|| info.x == info.x_max - 1) && info.current_char != '1')
				return (1);
			else if (info.current_char == 'P')
				info.player++;
			else if (info.current_char == 'E')
				info.exit++;
			else if (!(info.current_char == 'C' || \
			info.current_char == '1' || info.current_char == '0'))
				return (1);
			info.x++;
		}
		info.y++;
	}
	if (info.player != 1 || info.exit != 1 || info.total_coin == 0)
		return (1);
	return (0);
}

int	check_position(char **map, t_mapinfo info)
{
	char			**map_info[2];
	t_back_track	*player;
	char			**visited;

	visited = creat_dfs_map(info);
	player = NULL;
	map_info[0] = map;
	map_info[1] = visited;
	backtrack_coin(map_info, info.x_player, info.y_player, &player);
	free_double_pointer(visited);
	if (get_total_visited(player, 'C') != info.total_coin)
		return (free_back_track(player), 1);
	free_back_track(player);
	player = NULL;
	visited = creat_dfs_map(info);
	map_info[1] = visited;
	backtrack(map_info, info.x_player, info.y_player, &player);
	free_double_pointer(visited);
	if (get_total_visited(player, 'E') == 0)
		return (free_back_track(player), 2);
	return (free_back_track(player), 0);
}

void	check_map(char **map)
{
	t_mapinfo	info;
	int			status;

	info = initialize_map_info(map);
	if (check_map_dimension(map, info) == 1)
	{
		ft_printf("Error: The map is invalid.\n");
		ft_printf("Possible reasons could be incorrect \
dimensions or missing player/coin/exit door.\n");
		free_double_pointer(map);
		exit(EXIT_FAILURE);
	}
	status = check_position(map, info);
	if (status == 1)
	{
		ft_printf("Error: The player cannot reach all coins.\n");
		free_double_pointer(map);
		exit(EXIT_FAILURE);
	}
	if (status == 2)
	{
		ft_printf("Error: The player cannot reach the exit door.\n");
		free_double_pointer(map);
		exit(EXIT_FAILURE);
	}
}
