/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:29:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 12:17:30 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_draw_img(void *img, t_window *window, int x, int y);
static void	ft_update_zones(int timesx, int timesy, t_window *window);

void	ft_draw_map(t_assets *assets, t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == '1')
				ft_draw_img(assets->wall->img, window, j + 1, i + 1);
			if (window->map[i][j] == '0')
				ft_draw_img(assets->ground->img, window, j + 1, i + 1);
			if (window->map[i][j] == 'C')
				ft_draw_img(assets->collectible->img, window, j + 1, i + 1);
			if (window->map[i][j] == 'E')
				ft_draw_img(assets->exit_off->img, window, j + 1, i + 1);
			if (window->map[i][j] == '2')
				ft_draw_img(assets->exit_on->img, window, j + 1, i + 1);
			if (window->map[i][j] == 'P')
				ft_draw_img(assets->player->img, window, j + 1, i + 1);
			j++;
		}
		i++;
	}
}

static void	ft_draw_img(void *img, t_window *window, int x, int y)
{
	int	pos[2];
	int	timesx;
	int	timesy;

	ft_player_pos(window->map, pos);
	pos[0]++;
	pos[1]++;
	x *= 24;
	y *= 24;
	timesx = (pos[1] * 24) / 1280;
	timesy = (pos[0] * 24) / 720;
	ft_update_zones(timesx, timesy, window);
	if (timesx || timesy)
	{
		while (timesx--)
			x -= 1280;
		while (timesy--)
			y -= 720;
	}
	if ((x >= 0 && x < 1280) && y >= 0 && y < 720)
		mlx_put_image_to_window(window->mlx, window->win, img, x, y);
}

void	ft_clean_window(t_window *window)
{
	void	*clean;

	clean = mlx_new_image(window->mlx, WINDOW_W, WINDOW_H);
	mlx_put_image_to_window(window->mlx, window->win, clean, 0, 0);
	mlx_destroy_image(window->mlx, clean);
}

static void	ft_update_zones(int timesx, int timesy, t_window *window)
{
	if (timesx != window->zonex || timesy != window->zoney)
	{
		window->zonex = timesx;
		window->zoney = timesy;
		ft_clean_window(window);
	}
}
