/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/27 09:24:36 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


int	handle_no_event(void *window)
{
	if (window)
		return (0);
	return (0);
}

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(window->mlx, window->win);
	return (0);
}

int	main(void)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WINDOW_W, WINDOW_H, "so_long");
	
	mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_key_hook(window.win, handle_input, &window);
	mlx_loop(window.mlx);

	mlx_destroy_display(window.mlx);
	free(window.mlx);
	return (0);
}
