/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:55:38 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 14:04:23 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initialize_forks(pthread_mutex_t *forks, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_destroy_forks(pthread_mutex_t *forks, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
