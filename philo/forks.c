/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:04:53 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 15:05:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_one_fork(t_philo *philo);

int	ft_take_forks(t_philo *philo)
{
	if (!pthread_mutex_lock(&philo->eating)
		&& philo->id % 2 == 0 && !philo->meals)
	{
		pthread_mutex_unlock(&philo->eating);
		usleep(150);
	}
	else
		pthread_mutex_unlock(&philo->eating);
	if (philo->r_fork)
	{
		pthread_mutex_lock(&philo->left_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
	}
	else
		return (ft_one_fork(philo));
	return (1);
}

static int	ft_one_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_print_status(philo, "has taken a fork");
	while (ft_read_stage(philo->info))
		usleep(500);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}
