/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:06:03 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 11:41:45 by pabernar         ###   ########.fr       */
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
	ft_load_assets_map_addr(assets);
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
	ft_load_assets_player_addr(assets);
	return (1);
}

void	ft_load_assets_map_addr(t_assets *assets)
{
	assets->wall->addr = mlx_get_data_addr(assets->wall->img,
			&assets->wall->bpp, &assets->wall->line_len,
			&assets->wall->endian);
	assets->ground->addr = mlx_get_data_addr(assets->ground->img,
			&assets->ground->bpp, &assets->ground->line_len,
			&assets->ground->endian);
	assets->collectible->addr = mlx_get_data_addr(assets->collectible->img,
			&assets->collectible->bpp, &assets->collectible->line_len,
			&assets->collectible->endian);
	assets->exit_off->addr = mlx_get_data_addr(assets->exit_off->img,
			&assets->exit_off->bpp, &assets->exit_off->line_len,
			&assets->exit_off->endian);
	assets->exit_on->addr = mlx_get_data_addr(assets->exit_on->img,
			&assets->exit_on->bpp, &assets->exit_on->line_len,
			&assets->exit_on->endian);
}

void	ft_load_assets_player_addr(t_assets *assets)
{
	assets->player_up->addr = mlx_get_data_addr(assets->player_up->img,
			&assets->player_up->bpp, &assets->player_up->line_len,
			&assets->player_up->endian);
	assets->player_down->addr = mlx_get_data_addr(assets->player_down->img,
			&assets->player_down->bpp, &assets->player_down->line_len,
			&assets->player_down->endian);
	assets->player_left->addr = mlx_get_data_addr(assets->player_left->img,
			&assets->player_left->bpp, &assets->player_left->line_len,
			&assets->player_left->endian);
	assets->player_right->addr = mlx_get_data_addr(assets->player_right->img,
			&assets->player_right->bpp, &assets->player_right->line_len,
			&assets->player_right->endian);
}
