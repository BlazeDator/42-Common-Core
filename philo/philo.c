/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 15:07:09 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	TODO:
		Implement eating sleeping thinking and dying
*/
static int	ft_philo_eat(t_philo *philo);
static int	ft_philo_sleep(t_philo *philo);

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->threads_mutex);
	pthread_mutex_unlock(&philo->info->threads_mutex);
	ft_start_dates(philo, philo->info);
	while (ft_read_stage(philo->info))
	{
		ft_print_status(philo, "is thinking");
		if (!ft_read_stage(philo->info) || !ft_philo_eat(philo))
			return (0);
		if (!ft_read_stage(philo->info) || !ft_philo_sleep(philo))
			return (0);
	}
	return (0);
}

static int	ft_philo_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return (0);
	ft_print_status(philo, "is eating");
	ft_meal_date(philo, philo->info);
	pthread_mutex_lock(&philo->eating);
	philo->meals++;
	pthread_mutex_unlock(&philo->eating);
	while (!pthread_mutex_lock(&philo->info->time_mutex)
		&& !(ft_diff_ms(&philo->info->current, &philo->last_meal) 
			>= philo->info->time_eat))
	{
		pthread_mutex_unlock(&philo->info->time_mutex);
		if (!ft_read_stage(philo->info))
		{
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		usleep(500);
	}
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

static int	ft_philo_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_sleep_date(philo, philo->info);
	while (!pthread_mutex_lock(&philo->info->time_mutex)
		&& !(ft_diff_ms(&philo->info->current, &philo->last_sleep) 
			>= philo->info->time_sleep))
	{
		pthread_mutex_unlock(&philo->info->time_mutex);
		if (!ft_read_stage(philo->info))
			return (0);
		usleep(500);
	}
	return (1);
}

void	ft_print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->time_mutex);
	printf("%i %i %s\n", 
		ft_diff_ms(&philo->info->current, &philo->info->start), 
		philo->id,
		str); 
	pthread_mutex_unlock(&philo->info->time_mutex);
}
