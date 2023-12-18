/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:06:03 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/18 09:03:27 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_load_assets_map(t_assets *assets, t_window *window)
{
	assets->wall = malloc(sizeof(t_img));
	assets->ground = malloc(sizeof(t_img));
	assets->collectible = malloc(sizeof(t_img));
	assets->exit_off = malloc(sizeof(t_img));
	assets->exit_on = malloc(sizeof(t_img));
	if ((!assets->exit_on) || (!assets->wall) || (!assets->ground)
		|| (!assets->collectible) || (!assets->exit_off))
		return (0);
	assets->wall->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/terrain/wall.xpm",
			&assets->wall->width, &assets->wall->height);
	assets->ground->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/terrain/ground.xpm",
			&assets->ground->width, &assets->ground->height);
	assets->collectible->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/objects/collectible.xpm",
			&assets->collectible->width, &assets->collectible->height);
	assets->exit_off->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/objects/exit.xpm",
			&assets->exit_off->width, &assets->exit_off->height);
	assets->exit_on->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/objects/exit-active.xpm",
			&assets->exit_on->width, &assets->exit_on->height);
	return (1);
}

int	ft_load_assets_player(t_assets *assets, t_window *window)
{
	assets->player_up = malloc(sizeof(t_img));
	assets->player_down = malloc(sizeof(t_img));
	assets->player_left = malloc(sizeof(t_img));
	assets->player_right = malloc(sizeof(t_img));
	if ((!assets->player_up) || (!assets->player_down)
		|| (!assets->player_left) || (!assets->player_right))
		return (0);
	assets->player_up->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/player/player-up.xpm",
			&assets->player_up->width, &assets->player_up->height);
	assets->player_down->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/player/player-down.xpm",
			&assets->player_down->width, &assets->player_down->height);
	assets->player_left->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/player/player-left.xpm",
			&assets->player_left->width, &assets->player_left->height);
	assets->player_right->img = mlx_xpm_file_to_image(window->mlx,
			"./assets/pixel_poem/player/player-right.xpm",
			&assets->player_right->width, &assets->player_right->height);
	return (1);
}
