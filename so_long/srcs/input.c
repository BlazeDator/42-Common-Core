/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 16:04:33 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_input(int keysym, t_window *window)
{
	int	pos[2];

	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_w)
	{
		ft_player_pos(window->map, pos);
		window->map[pos[0]][pos[1]] = '0';
		pos[0]--;
		window->map[pos[0]][pos[1]] = 'P';
	}
	if (keysym == XK_s)
	{
		ft_player_pos(window->map, pos);
		window->map[pos[0]][pos[1]] = '0';
		pos[0]++;
		window->map[pos[0]][pos[1]] = 'P';
	}
	if (keysym == XK_a)
	{
		ft_player_pos(window->map, pos);
		window->map[pos[0]][pos[1]] = '0';
		pos[1]--;
		window->map[pos[0]][pos[1]] = 'P';
	}
	if (keysym == XK_d)
	{
		ft_player_pos(window->map, pos);
		window->map[pos[0]][pos[1]] = '0';
		pos[1]++;
		window->map[pos[0]][pos[1]] = 'P';
	}
	return (0);
}
