/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:38:36 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/02 14:39:29 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eat(t_philo *philo)
{
	t_timeval	current;

	gettimeofday(&current, 0);
	if (philo->stage)
	{
		if (ft_diff_ms(current, philo->last_meal) 
			>= philo->info->time_eat)
		{
			ft_set_stage(philo, 2);
			return (0);
		}
	}
	return (1);
}

int	ft_philo_sleep(t_philo *philo)
{
	t_timeval	current;

	gettimeofday(&current, 0);
	if (philo->stage)
	{
		if (ft_diff_ms(current, philo->last_sleep) 
			>= philo->info->time_sleep)
		{
			ft_set_stage(philo, 1);
			return (0);
		}
	}
	return (1);
}
