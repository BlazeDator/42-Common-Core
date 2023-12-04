/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/04 16:05:37 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_no_event(t_window *window)
{
	if (window)
		return (0);
	return (0);
}

int	window_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	ft_free_map(window->map);
	exit(0);
	return (0);
}

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		window_close(window);
	if (keysym == XK_Up)
		mlx_put_image_to_window(window->mlx, window->win, window->img, 50, 50);
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	window;
	char		**map;

	if (argc != 2)
		return (ft_printf("./so_long <nameofmap.ber>\n"));
	map = ft_process_map(argv[1]);
	if (!map)
		return (0);
	window.map = map;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WINDOW_W, WINDOW_H, "so_long");
	mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_key_hook(window.win, handle_input, &window);
	mlx_hook(window.win, 17, 0, window_close, &window);

	// image test
	void	*img;
	char	*relative_path = "./assets/Pixel_Poem/final/player-down.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(window.mlx, relative_path, &img_width, &img_height);
	window.img = img;
	mlx_loop(window.mlx);
	return (0);
}
