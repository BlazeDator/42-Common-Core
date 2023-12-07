/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:16:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 16:32:00 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_traveler(char **map, int x, int y);
static int	ft_traveler_check(char **map);
static void	ft_cleaner(char **map, int x, int y);

int	ft_check_path(char **map)
{
	int	start[2];

	start[0] = 0;
	start[1] = 0;
	ft_player_pos(map, start);
	ft_traveler(map, start[0], start[1]);
	if (!ft_traveler_check(map))
		return (0);
	ft_cleaner(map, start[0], start[1]);
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
			}
			j++;
		}
		i++;
	}
}

static void	ft_traveler(char **map, int x, int y)
{
	if (map[x][y] == 'P')
		map[x][y] = 'J';
	if (map[x][y] == '0')
		map[x][y] = 'X';
	if (map[x][y] == 'E')
		map[x][y] = 'S';
	if (map[x][y] == 'C')
		map[x][y] = 'D';
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

static void	ft_cleaner(char **map, int x, int y)
{
	if (map[x][y] == 'J')
		map[x][y] = 'P';
	if (map[x][y] == 'X')
		map[x][y] = '0';
	if (map[x][y] == 'S')
		map[x][y] = 'E';
	if (map[x][y] == 'D')
		map[x][y] = 'C';
	x--;
	if (map[x][y] == 'X' || map[x][y] == 'D' || map [x][y] == 'S')
		ft_cleaner(map, x, y);
	x += 2;
	if (map[x][y] == 'X' || map[x][y] == 'D' || map [x][y] == 'S')
		ft_cleaner(map, x, y);
	x--;
	y--;
	if (map[x][y] == 'X' || map[x][y] == 'D' || map [x][y] == 'S')
		ft_cleaner(map, x, y);
	y += 2;
	if (map[x][y] == 'X' || map[x][y] == 'D' || map [x][y] == 'S')
		ft_cleaner(map, x, y);
}
