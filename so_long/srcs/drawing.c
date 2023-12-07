/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:29:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 10:21:20 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_draw_img(void *img, t_window *window, int x, int y);

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
				ft_draw_img(assets->player_down->img, window, j + 1, i + 1);
			j++;
		}
		i++;
	}
}

static void	ft_draw_img(void *img, t_window *window, int x, int y)
{
	mlx_put_image_to_window(window->mlx, window->win, 
		img, x * 24, y * 24);
}
/*
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	color(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
*/
