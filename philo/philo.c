/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/18 09:16:24 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_eat(t_philo *philo);
static int	ft_philo_sleep(t_philo *philo);
static int	ft_philo_think(t_philo *philo, int parity);

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->threads_mutex);
	pthread_mutex_unlock(&philo->info->threads_mutex);
	while (ft_read_stage(philo->info))
	{
		ft_philo_think(philo, 1);
		if (!philo->r_fork && !ft_one_fork(philo))
			return (0);
		if (!ft_read_stage(philo->info) || !ft_philo_eat(philo))
			return (0);
		if (!ft_read_stage(philo->info) || !ft_philo_sleep(philo))
			return (0);
		if (!ft_read_stage(philo->info) || !ft_philo_think(philo, 0))
			return (0);
	}
	return (0);
}

static int	ft_philo_eat(t_philo *philo)
{
	ft_take_forks(philo);
	ft_meal_date(philo, philo->info);
	ft_print_status(philo, "is eating");
	while (!pthread_mutex_lock(&philo->info->time_mutex)
		&& !(ft_diff_ms(&philo->info->current, &philo->last_meal) 
			> philo->info->time_eat)
		&& ft_read_stage(philo->info))
	{
		pthread_mutex_unlock(&philo->info->time_mutex);
		usleep(500);
	}
	pthread_mutex_unlock(&philo->info->time_mutex);
	ft_free_forks(philo);
	pthread_mutex_lock(&philo->eating);
	philo->meals++;
	pthread_mutex_unlock(&philo->eating);
	return (1);
}

static int	ft_philo_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_sleep_date(philo, philo->info);
	while (!pthread_mutex_lock(&philo->info->time_mutex)
		&& !(ft_diff_ms(&philo->info->current, &philo->last_sleep) 
			> philo->info->time_sleep)
		&& ft_read_stage(philo->info))
	{
		pthread_mutex_unlock(&philo->info->time_mutex);
		usleep(500);
	}
	pthread_mutex_unlock(&philo->info->time_mutex);
	return (1);
}

static int	ft_philo_think(t_philo *philo, int parity)
{
	if (philo->id % 2 == parity)
	{
		ft_print_status(philo, "is thinking");
		usleep(1000);
	}
	return (1);
}

void	ft_print_status(t_philo *philo, char *str)
{
	if (ft_read_stage(philo->info))
	{
		pthread_mutex_lock(&philo->info->time_mutex);
		printf("%i %i %s\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), 
			philo->id,
			str); 
		pthread_mutex_unlock(&philo->info->time_mutex);
	}
}
