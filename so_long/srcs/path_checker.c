/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:16:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/04 12:33:47 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_traveler(char **map, int x, int y);
static int	ft_traveler_check(char **map);

int	ft_check_path(char **map, int lines, int len)
{
	int	start[2];

	ft_player_pos(map, start);
	ft_printf("lines: %i\nline-length:%i\n", lines, len);
	ft_printf("p-posx: %i\np-posy: %i\n", start[0], start[1]);
	ft_printf("\n\n");
	ft_debug_show_map(map);
	ft_traveler(map, start[0], start[1]);
	ft_printf("\n\n");
	ft_debug_show_map(map);
	if (!ft_traveler_check(map))
		return (0);
	return (1);
}

void	ft_player_pos(char **map, int *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos[0] = i;
				pos[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_traveler(char **map, int x, int y)
{
	map[x][y] = 'X';
	x--;
	if (map[x][y] == '0' || map[x][y] == 'C' || map [x][y] == 'E')
		ft_traveler(map, x, y);
	x += 2;
	if (map[x][y] == '0' || map[x][y] == 'C' || map [x][y] == 'E')
		ft_traveler(map, x, y);
	x--;
	y--;
	if (map[x][y] == '0' || map[x][y] == 'C' || map [x][y] == 'E')
		ft_traveler(map, x, y);
	y += 2;
	if (map[x][y] == '0' || map[x][y] == 'C' || map [x][y] == 'E')
		ft_traveler(map, x, y);
}

static int	ft_traveler_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
