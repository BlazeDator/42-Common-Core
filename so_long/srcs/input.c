/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 12:52:47 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_w)
	{
		window->player_y -= 24;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_up->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_s)
	{
		window->player_y += 24;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_down->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_a)
	{
		window->player_x -= 24;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_left->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_d)
	{
		window->player_x += 24;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_right->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_f)
	{
		int i = 0;
		int j = 0;

		while (window->map[i])
		{
			j = 0;
			while (window->map[i][j])
			{
				if (window->map[i][j] == '1')
					mlx_put_image_to_window(window->mlx, window->win, 
						window->assets->wall->img,
						(j + 1) * 24, (i + 1) * 24);
				if (window->map[i][j] == '0')
					mlx_put_image_to_window(window->mlx, window->win, 
						window->assets->ground->img,
						(j + 1) * 24, (i + 1) * 24);
				j++;
			}
			i++;
		}
	}
	return (0);
}
