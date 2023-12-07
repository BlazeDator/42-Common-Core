/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 16:35:39 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_player_move(t_window *window, int *pos, char c, int *move);
static int	ft_check_collectibles(t_window *window);
static void	ft_change_directions(t_window *window, char c);
static void	ft_restore_exit(t_window *window);

int	handle_input(int keysym, t_window *window)
{
	int	pos[2];
	int	move;

	move = 0;
	ft_player_pos(window->map, pos);
	if (keysym == 65307)
		window_close(window);
	else if (keysym == 119)
		ft_player_move(window, pos, 'w', &move);
	else if (keysym == 115)
		ft_player_move(window, pos, 's', &move);
	else if (keysym == 97)
		ft_player_move(window, pos, 'a', &move);
	else if (keysym == 100)
		ft_player_move(window, pos, 'd', &move);
	if (move)
	{
		window->moves++;
		ft_printf("Moves: %i\n", window->moves);
	}
	if (!ft_check_collectibles(window) && pos[0] == window->end[0] 
		&& pos[1] == window->end[1] && window->map[pos[0]][pos[1]] == '2')
		ft_game_over(window);
	ft_restore_exit(window);
	return (0);
}

static void	ft_player_move(t_window *window, int *pos, char c, int *move)
{
	char	**map;

	map = window->map;
	if ((map[pos[0] - 1][pos[1]] != '1') && (c == 'w') && (*move)++ == 0)
	{
		window->map[pos[0]--][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	else if ((map[pos[0] + 1][pos[1]] != '1') && (c == 's') && (*move)++ == 0)
	{
		window->map[pos[0]++][pos[1]] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	else if ((map[pos[0]][pos[1] - 1] != '1') && (c == 'a') && (*move)++ == 0)
	{
		window->map[pos[0]][pos[1]--] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	else if ((map[pos[0]][pos[1] + 1] != '1') && (c == 'd') && (*move)++ == 0)
	{
		window->map[pos[0]][pos[1]++] = '0';
		window->map[pos[0]][pos[1]] = 'P';
	}
	ft_change_directions(window, c);
}

static int	ft_check_collectibles(t_window *window)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (!collectibles)
		window->map[window->end[0]][window->end[1]] = '2';
	return (collectibles);
}

static void	ft_change_directions(t_window *window, char c)
{
	if (c == 'w')
		window->assets->player = window->assets->player_up;
	else if (c == 's')
		window->assets->player = window->assets->player_down;
	else if (c == 'a')
		window->assets->player = window->assets->player_left;
	else if (c == 'd')
		window->assets->player = window->assets->player_right;
}

static void	ft_restore_exit(t_window *window)
{
	if (window->map[window->end[0]][window->end[1]] == '0')
		window->map[window->end[0]][window->end[1]] = 'E';
		
}
