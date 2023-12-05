/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/05 11:15:47 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	ft_check_wall_line(char *str);
static int	ft_check_symbols(char *str);

int	ft_valid_map(char **map, int lines)
{
	unsigned int	len;

	len = ft_strlen(*map);
	if (!ft_check_wall_line(map[0])
		|| !ft_check_wall_line(map[(lines - 1)]))
		return (ft_printf("Error\nTop or bottom wall isn't closed\n"), 0);
	while (*map)
	{
		if (ft_strlen(*map) != len)
			return (ft_printf("Error\nDifferent length lines\n"), 0);
		if ((*map)[0] != '1' || (*map)[ft_strlen(*map) - 1] != '1')
			return (ft_printf("Error\nLine not walled up\n"), 0);
		if (!ft_check_symbols(*map))
			return (ft_printf("Error\nCheck the symbols\n"), 0);
		map++;
	}
	if (!ft_check_symbols(0))
		return (0);
	if (len == (unsigned int)lines)
		return (ft_printf("Error\nThat's a square\n"), 0);
	if (!ft_check_path(map - lines))
		return (ft_printf("Error\nNo possible path\n"), 0);
	return (1);
}

static int	ft_check_wall_line(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int	ft_check_symbols(char *str)
{
	static int	exit;
	static int	collectibles;
	static int	player;

	if (!str)
	{
		if (exit != 1 || player != 1)
			return (ft_printf("Error\nOnly 1 player and 1 exit\n"), 0);
		if (collectibles < 1)
			return (ft_printf("Error\nneeds more collectibles\n"), 0);
	}
	while (str && *str)
	{
		if (*str != '1' && *str != '0' && *str != 'C' 
			&& *str != 'E' && *str != 'P')
			return (0);
		if (*str == 'C')
			collectibles++;
		if (*str == 'E')
			exit++;
		if (*str == 'P')
			player++;
		str++;
	}
	return (1);
}
