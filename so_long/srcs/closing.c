/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:08:26 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/05 11:20:44 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	window_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	ft_free_map(window->map);
	exit(0);
	return (0);
}
