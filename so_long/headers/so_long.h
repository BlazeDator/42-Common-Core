/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/18 09:12:35 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WINDOW_W 624
# define WINDOW_H 360

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
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
	t_img	*player;
}		t_assets;

typedef struct s_window
{
	t_assets	*assets;
	void		*mlx;
	void		*win;
	char		**map;
	int			moves;
	int			end[2];
	int			zonex;
	int			zoney;
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
int		handle_frames(t_window *window);
/*
	closing.c
*/
void	ft_game_over(t_window *window);
int		window_close(t_window *window);
/*
	assets.c
*/
int		ft_load_assets_map(t_assets *assets, t_window *window);
int		ft_load_assets_player(t_assets *assets, t_window *window);
/*
	drawing.c
*/
void	ft_draw_map(t_assets *assets, t_window *window);
void	ft_clean_window(t_window *window);
/*
	helpers.c
*/
size_t	ft_strlen_no_nl(const char *s);
void	ft_end_pos(char **map, int *end);
/*
	debug.c
*/
void	ft_debug_show_map(char **map);
#endif
