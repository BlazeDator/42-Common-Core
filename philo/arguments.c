/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:35:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 11:55:16 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_atoi(int num, char *str);

int	ft_check_arguments(int argc, char **argv, t_info *info)
{
	info->total_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (!ft_check_atoi(info->total_philos, argv[1])
		|| !ft_check_atoi(info->time_die, argv[2])
		|| !ft_check_atoi(info->time_eat, argv[3])
		|| !ft_check_atoi(info->time_sleep, argv[4])
		|| info->total_philos < 1
		|| info->time_die < 1
		|| info->time_eat < 1
		|| info->time_sleep < 1)
		return (0);
	if (argc == 6)
	{
		info->times_to_eat = ft_atoi(argv[5]);
		if (!ft_check_atoi(info->times_to_eat, argv[5])
			|| info->times_to_eat < 1)
			return (0);
	}
	else
		info->times_to_eat = 0;
	return (1);
}

static int	ft_check_atoi(int num, char *str)
{
	char	*numstr;

	numstr = ft_itoa(num);
	if (ft_strncmp(numstr, str, ft_strlen(str)))
	{
		free(numstr);
		return (0);
	}
	free(numstr);
	return (1);
}
