/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:08:26 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 10:40:08 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_destroy_assets(t_assets *assets, t_window *window);

void	ft_game_over(t_window *window)
{
	ft_printf("Game Over! in %i moves.\n", window->moves);
	window_close(window);
}

int	window_close(t_window *window)
{
	ft_destroy_assets(window->assets, window);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	ft_free_map(window->map);
	exit(0);
	return (0);
}

static void	ft_destroy_assets(t_assets *assets, t_window *window)
{
	mlx_destroy_image(window->mlx, assets->wall->img);
	mlx_destroy_image(window->mlx, assets->ground->img);
	mlx_destroy_image(window->mlx, assets->collectible->img);
	mlx_destroy_image(window->mlx, assets->exit_off->img);
	mlx_destroy_image(window->mlx, assets->exit_on->img);
	mlx_destroy_image(window->mlx, assets->player_up->img);
	mlx_destroy_image(window->mlx, assets->player_down->img);
	mlx_destroy_image(window->mlx, assets->player_left->img);
	mlx_destroy_image(window->mlx, assets->player_right->img);
	free(assets->wall);
	free(assets->ground);
	free(assets->collectible);
	free(assets->exit_off);
	free(assets->exit_on);
	free(assets->player_up);
	free(assets->player_down);
	free(assets->player_left);
	free(assets->player_right);
}
