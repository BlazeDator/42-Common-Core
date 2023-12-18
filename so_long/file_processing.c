/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/07 16:38:53 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char	**ft_map_error(char *str);
static int	ft_bad_extension(char *str);
static int	ft_file_lines(char *str);
static void	ft_read_to_array(int fd, char **map);

char	**ft_process_map(char *str)
{
	char	**map;
	int		fd;
	int		lines;

	if (ft_bad_extension(str))
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_map_error("Error\nFile doesn't exist\n"));
	lines = ft_file_lines(str);
	if (lines < 3)
		return (ft_map_error("Error\nNot enough lines for valid map\n"));
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (ft_map_error("Error\nMalloc failed\n"));
	ft_read_to_array(fd, map);
	close(fd);
	if (ft_valid_map(map, lines))
		return (map);
	ft_free_map(map);
	return (0);
}

static char	**ft_map_error(char *str)
{
	ft_printf(str);
	return (0);
}

static int	ft_bad_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (ft_printf("Error\n./so_long <nameofmap.ber>\n"));
	len--;
	if (str[len - 3] != '.' || str[len - 2] != 'b'
		|| str[len - 1] != 'e' || str[len] != 'r')
		return (ft_printf("Error\n./so_long <nameofmap.ber>\n"));
	return (0);
}

static int	ft_file_lines(char *str)
{
	char	*line;
	int		lines;
	int		fd;

	lines = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static void	ft_read_to_array(int fd, char **map)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
		*map = malloc(ft_strlen_no_nl(temp) + 1);
		if (!*map)
			return ;
		ft_strlcpy(*map, temp, ft_strlen_no_nl(temp) + 1);
		free(temp);
		map++;
		temp = get_next_line(fd);
	}
	*map = 0;
}
