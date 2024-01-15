/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:16:50 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 16:03:23 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_mutexes(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&t_info.threads_mutex, 0);
	pthread_mutex_init(&t_info.time_mutex, 0);
	while (i < info->total_philos)
	{
		pthread_mutex_init(&philos[i].left_fork, 0);
		pthread_mutex_init(&philos[i].stage_mutex, 0);
		i++;
	}
}
