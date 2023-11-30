/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/27 10:00:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	ft_check_wall_line(char *str);
/*
TODO:
	needs only 1 exit
	needs only 1 player position
	needs 1 collectible
	needs a valid path, to collect and walk to the exit
*/

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
		map++;
	}
	if (len == (unsigned int)lines)
		return (ft_printf("Error\nThat's a square\n"), 0);
	ft_debug_show_map(map - lines);
	return (0);
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
