/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 09:19:53 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_assets	assets;
	char		**map;

	if (argc != 2)
		return (ft_printf("./so_long <nameofmap.ber>\n"));
	map = ft_process_map(argv[1]);
	if (!map)
		return (0);
	window.moves = 0;
	window.map = map;
	window.assets = &assets;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WINDOW_W, WINDOW_H, "so_long");
	if (!ft_load_assets_map(window.assets, &window) 
		|| !ft_load_assets_player(window.assets, &window))
		window_close(&window);
	mlx_loop_hook(window.mlx, handle_no_event, &window);
	mlx_hook(window.win, 2, (1L << 0), handle_input, &window);
	mlx_hook(window.win, 17, 0, window_close, &window);
	mlx_loop(window.mlx);
	return (0);
}
