/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:16:50 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 12:35:16 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->threads_mutex, 0)
		|| pthread_mutex_init(&info->time_mutex, 0)
		|| pthread_mutex_init(&info->stage_mutex, 0))
		return (0);
	while (i < info->total_philos)
	{
		if (pthread_mutex_init(&philos[i].left_fork, 0)
			|| pthread_mutex_init(&philos[i].eating, 0))
			return (0);
		i++;
	}
	return (1);
}

void	ft_destroy_mutexes(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->threads_mutex);
	pthread_mutex_destroy(&info->time_mutex);
	pthread_mutex_destroy(&info->stage_mutex);
	while (i < info->total_philos)
	{
		pthread_mutex_destroy(&philos[i].left_fork);
		pthread_mutex_destroy(&philos[i].eating);
		i++;
	}
}
