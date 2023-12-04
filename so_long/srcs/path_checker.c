/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:16:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:16 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_path(char **map, int lines, int len)
{
	int	start[2];

	ft_player_pos(map, start);
	ft_printf("lines: %i\nline-length:%i\n", lines, len);
	ft_printf("p-posx: %i\np-posy: %i\n", start[0], start[1]);
	ft_debug_show_map(map);
	return (0);
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
