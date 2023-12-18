/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:57:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 16:35:39 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t	ft_strlen_no_nl(const char *s)
{
	size_t			count;

	count = 0;
	while (*s && *s != '\n')
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_end_pos(char **map, int *end)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				end[0] = i;
				end[1] = j;
			}
			j++;
		}
		i++;
	}
}
