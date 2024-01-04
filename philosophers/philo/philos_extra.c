/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:38:36 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/04 11:22:51 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eat(t_philo *philo)
{
	if (philo->stage)
	{
		if (ft_diff_ms(&philo->info->current, &philo->last_meal) 
			> philo->info->time_eat)
		{
			ft_set_stage(philo, 2);
			return (0);
		}
	}
	else
		return (0);
	return (1);
}

int	ft_philo_sleep(t_philo *philo)
{
	if (philo->stage)
	{
		if (ft_diff_ms(&philo->info->current, &philo->last_sleep) 
			> philo->info->time_sleep)
		{
			ft_set_stage(philo, 1);
			return (0);
		}
	}
	else
		return (0);
	return (1);
}

void	ft_print_status(t_philo *philo, char *str)
{
	printf("%i %i %s\n", 
		ft_diff_ms(&philo->info->current, &philo->info->start), 
		philo->id,
		str); 
}

void	ft_update_date(t_timeval *dest, t_timeval *src)
{
	dest->tv_sec = src->tv_sec;
	dest->tv_usec = src->tv_usec;
}
