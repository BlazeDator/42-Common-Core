/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:10:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 09:57:26 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_Up)
	{
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_up->img, 500, 360);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_down->img, 400, 360);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_left->img, 300, 360);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->player_right->img, 200, 360);
	}
	if (keysym == XK_Down)
	{
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->wall->img, 600, 500);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->ground->img, 400, 500);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->collectible->img, 300, 500);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->exit_off->img, 200, 500);
		mlx_put_image_to_window(window->mlx, window->win, 
			window->assets->exit_on->img, 100, 500);
	}
	return (0);
}
