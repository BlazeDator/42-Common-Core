/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:21:52 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/27 10:00:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	ft_bad_extension(char *str);

char	**ft_process_map(char	*str)
{
	int	fd;

	if (ft_bad_extension(str))
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile doesn't exist\n");
		return (0);
	}
	return (0);
}

int	ft_bad_extension(char *str)
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
