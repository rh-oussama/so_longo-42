/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:52:48 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/18 12:01:05 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *maps)
{
	int		fd;
	char	*str;
	char	*tmp;
	char	*old_str;
	char	**list;

	str = ft_strdup("");
	fd = open(maps, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		old_str = str;
		str = ft_strjoin(str, tmp);
		free(old_str);
		free(tmp);
		tmp = get_next_line(fd);
	}
	get_next_line(INT_MAX);
	free(tmp);
	close(fd);
	list = ft_split(str, '\n');
	return (free(str), list);
}

t_position	*ft_lstlast(t_position *lst)
{
	t_position	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_position **lst, t_position *new)
{
	t_position	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_position	*get_position(t_gamesettings *game, int x, int y)
{
	int			i;
	t_position	*positions[5];
	t_position	*current;

	i = 0;
	positions[0] = game->player;
	positions[1] = game->exit_door;
	positions[2] = game->coin;
	positions[3] = game->wall;
	positions[4] = game->background;
	while (i < 5)
	{
		current = positions[i];
		while (current != NULL)
		{
			if (current->x == x && current->y == y)
				return (current);
			current = current->next;
		}
		i++;
	}
	return (NULL);
}

void	update_key_left(t_gamesettings *game)
{
	t_position	*tmp;
	int			i;

	tmp = game->coin;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->state == 1)
			i++;
		tmp = tmp->next;
	}
	game->key_left = i;
	if (i == 0)
	{
		game->exit_door->png = game->image.tresure02;
		game->door_open_close = 0;
	}
}
