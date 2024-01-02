/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:57:40 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/02 11:00:18 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_logic(t_philo *philo)
{
	while (philo->stage != 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		printf("timestamp %i has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("timestamp %i has taken a fork\n", philo->id);
		printf("timestamp %i is eating\n", philo->id);
		gettimeofday(&philo->last_meal, 0);
		philo->meals++;
		while (philo->stage == 1)
			continue ;
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("timestamp %i is sleeping\n", philo->id);
		gettimeofday(&philo->last_sleep, 0);
		while (philo->stage == 2)
			continue ;
		printf("timestamp %i is thinking\n", philo->id);
	}
}

void	ft_set_stage(t_philo *philo, int stage)
{
	pthread_mutex_lock(&philo->stage_mutex);
	if (stage == 1 && philo->stage == 2)
		philo->stage = 1;
	else if (stage == 2 && philo->stage == 1)
		philo->stage = 2;
	else
		philo->stage = 0;
	pthread_mutex_unlock(&philo->stage_mutex);
}

void	*say_hi(void *i)
{
	int	*x;

	x = (int *)i;
	printf("Thread %i: hi!\n", *x);
	return (0);
}

void	ft_initialize_philos(pthread_t *philos, t_info *info, int *numbers)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		numbers[i] = i;
		printf("Starting Thread %i\n", i);
		pthread_create(&philos[i], 0, say_hi, &numbers[i]);
		i++;
	}
}

void	ft_destroy_philos(pthread_t *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		pthread_join(philos[i], 0);
		printf("Deleting Thread %i\n", i);
		i++;
	}
}
