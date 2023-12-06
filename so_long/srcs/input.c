/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 10:58:15 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_w)
	{
		window->player_y -= 20;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_up->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_s)
	{
		window->player_y += 20;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_down->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_a)
	{
		window->player_x -= 20;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_left->img, 
			window->player_x, window->player_y);
	}
	if (keysym == XK_d)
	{
		window->player_x += 20;
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_right->img, 
			window->player_x, window->player_y);
	}
	return (0);
}
