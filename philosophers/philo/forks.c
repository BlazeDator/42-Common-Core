/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:55:38 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/03 11:09:36 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initialize_forks(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->time_mutex, 0);
	while (i < info->total_philos)
	{
		if (pthread_mutex_init(&philos[i].left_fork, 0) != 0)
			return (0);
		if (pthread_mutex_init(&philos[i].stage_mutex, 0) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_destroy_forks(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		pthread_mutex_destroy(&philos[i].left_fork);
		pthread_mutex_destroy(&philos[i].stage_mutex);
		i++;
	}
	pthread_mutex_destroy(&info->time_mutex);
}
