/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/05 11:20:22 by pabernar         ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	**map;
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
	debug.c
*/
void	ft_debug_show_map(char **map);
#endif
