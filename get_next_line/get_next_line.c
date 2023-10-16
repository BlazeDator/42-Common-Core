/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:08:14 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/16 10:31:14 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_buffer_is_empty(char	*buffer)
{
	int	i;

	i = 0;
	while (buffer[i] == 0 && i < BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
		return (1);
	return (0);
}

int	ft_str_has_newline(char	*str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read_clean_buffer(char *buffer, size_t maxchars)
{
	size_t	i;
	size_t	j;
	size_t	max;
	char	str[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
	ft_bzero((void *)str, (BUFFER_SIZE + 1));
	max = BUFFER_SIZE;
	if (maxchars)
		max = maxchars;
	while (i < max)
	{
		if (buffer[i] != '\n' && buffer[i] != '\0')
			str[j++] = buffer[i];
		else if (buffer[i] == '\n')
			str[j++] = '\n';
		buffer[i] = '\0';
		if (str[i++] == '\n')
			break ;
	}
	return (ft_strdup(str));
}

char	*ft_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	char		*next;
	char		*temp;
	size_t		charead;

	charead = 0;
	str = "";
	while (!ft_str_has_newline(str))
	{
		if (ft_buffer_is_empty(buffer))
			charead = read(fd, buffer, BUFFER_SIZE);
		if (!charead && !ft_strlen(str))
			return (0);
		else if (!charead && ft_strlen(str))
			break ;
		next = ft_read_clean_buffer(buffer, charead);
		temp = str;
		str = ft_strjoin(str, next);
		if (ft_strlen(temp) > 0)
			free(temp);
		free(next);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	return (ft_line(fd));
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	if (str)
	{
		printf("%s", str);
		free(str);
	}
	printf("\n\n| This was the first line |\n\n");
	str = get_next_line(fd);
	if (str)
	{
		printf("%s", str);
		free(str);
	}
	printf("\n\n| This was the second line |\n\n");
}*/
