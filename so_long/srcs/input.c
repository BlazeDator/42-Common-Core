/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 10:15:40 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_player_move(t_window *window, int *pos, char c, int *move);

int	handle_input(int keysym, t_window *window)
{
	int	pos[2];
	int	move;

	move = 0;
	ft_player_pos(window->map, pos);
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_w)
		ft_player_move(window, pos, 'w', &move);
	if (keysym == XK_s)
		ft_player_move(window, pos, 's', &move);
	if (keysym == XK_a)
		ft_player_move(window, pos, 'a', &move);
	if (keysym == XK_d)
		ft_player_move(window, pos, 'd', &move);
	if (move)
	{
		window->moves++;
		ft_printf("Moves: %i\n", window->moves);
	}
	return (0);
}

static void	ft_player_move(t_window *window, int *pos, char c, int *move)
{
	if ((window->map[pos[0] - 1][pos[1]] != '1') && (c == 'w')
		&& (window->map[pos[0] - 1][pos[1]] != 'E') && (*move)++ == 0)
	{
		window->map[pos[0]--][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0] + 1][pos[1]] != '1') && (c == 's')
		&& (window->map[pos[0] + 1][pos[1]] != 'E') && (*move)++ == 0)
	{
		window->map[pos[0]++][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0]][pos[1] - 1] != '1') && (c == 'a')
		&& (window->map[pos[0]][pos[1] - 1] != 'E') && (*move)++ == 0)
	{
		window->map[pos[0]][pos[1]--] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	if ((window->map[pos[0]][pos[1] + 1] != '1') && (c == 'd')
		&& (window->map[pos[0]][pos[1] + 1] != 'E') && (*move)++ == 0)
	{
		window->map[pos[0]][pos[1]++] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
}
