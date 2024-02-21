/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:10:23 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/21 21:14:36 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1 && str1[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	argv_checker(int argc, char **argv)
{
	char	*ext;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("[-] Usage: ./so_long <map>.ber", 2);
		exit(EXIT_FAILURE);
	}
	ext = argv[1] + (ft_strlen(argv[1]) - 4);
	if (ft_strcmp(ext, ".ber") != 0)
	{
		ft_putendl_fd("[!] Map extension must be .ber", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
}
