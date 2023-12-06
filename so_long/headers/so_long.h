/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/06 16:02:44 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WINDOW_W 1280
# define WINDOW_H 720

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_assets
{
	t_img	*wall;
	t_img	*ground;
	t_img	*collectible;
	t_img	*exit_off;
	t_img	*exit_on;
	t_img	*player_up;
	t_img	*player_down;
	t_img	*player_left;
	t_img	*player_right;
}		t_assets;

typedef struct s_window
{
	t_assets	*assets;
	void		*mlx;
	void		*win;
	char		**map;
}		t_window;
/*
	file_processing.c && file_processing_extras.c
*/
char	**ft_process_map(char *str);
int		ft_valid_map(char **map, int lines);
int		ft_free_map(char **map);
/*
	path_checker.c
*/
int		ft_check_path(char **map);
void	ft_player_pos(char **map, int *pos);
/*
	inputs.c
*/
int		handle_input(int keysym, t_window *window);
/*
	events.c
*/
int		handle_no_event(t_window *window);
/*
	closing.c
*/
int		window_close(t_window *window);
/*
	assets.c
*/
int		ft_load_assets_map(t_assets *assets, t_window *window);
int		ft_load_assets_player(t_assets *assets, t_window *window);
void	ft_load_assets_map_addr(t_assets *assets);
void	ft_load_assets_player_addr(t_assets *assets);
/*
	drawing.c
*/
void	ft_draw_map(t_assets *assets, t_window *window);
/*
	debug.c
*/
void	ft_debug_show_map(char **map);
#endif
/*
void	put_pixel(t_img *img, int x, int y, int color);
int		color(unsigned char t, unsigned char r, 
			unsigned char g, unsigned char b);
*/
