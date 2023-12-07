/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 09:15:33 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_player_move(t_window *window, int *pos, char c);

int	handle_input(int keysym, t_window *window)
{
	int	pos[2];

	ft_player_pos(window->map, pos);
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_w)
		ft_player_move(window, pos, 'w');
	if (keysym == XK_s)
		ft_player_move(window, pos, 's');
	if (keysym == XK_a)
		ft_player_move(window, pos, 'a');
	if (keysym == XK_d)
		ft_player_move(window, pos, 'd');
	return (0);
}

static void	ft_player_move(t_window *window, int *pos, char c)
{
	if ((window->map[pos[0] - 1][pos[1]] != '1')
		&& (window->map[pos[0] - 1][pos[1]] != 'E') && (c == 'w'))
	{
		window->map[pos[0]--][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0] + 1][pos[1]] != '1')
		&& (window->map[pos[0] + 1][pos[1]] != 'E') && (c == 's'))
	{
		window->map[pos[0]++][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0]][pos[1] - 1] != '1')
		&& (window->map[pos[0]][pos[1] - 1] != 'E') && (c == 'a'))
	{
		window->map[pos[0]][pos[1]--] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0]][pos[1] + 1] != '1')
		&& (window->map[pos[0]][pos[1] + 1] != 'E') && (c == 'd'))
	{
		window->map[pos[0]][pos[1]++] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
}
