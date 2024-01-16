/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:40:38 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 12:11:34 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philos(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].info = info;
		philos[i].r_fork = 1;
		if ((i + 1) < info->total_philos)
			philos[i].right_fork = &philos[i + 1].left_fork;
		else if (info->total_philos > 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].r_fork = 0;
		if (pthread_create(&philos[i].thread, 0, ft_philo, &philos[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_destroy_philos(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		pthread_join(philos[i].thread, 0);
		i++;
	}
}
