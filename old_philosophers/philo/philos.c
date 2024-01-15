/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:57:40 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 09:18:26 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_choice(t_philo *philo, int lock);

void	*ft_philo_logic(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (philo->stage)
	{
		ft_print_status(philo, "is thinking");
		usleep(100);
		if (!ft_forks_choice(philo, 1))
			return (0);
		ft_update_date(&philo->last_meal, &philo->info->current);
		ft_print_status(philo, "is eating");
		while (philo->stage == 1 && ft_philo_eat(philo))
			usleep(500);
		ft_forks_choice(philo, 0);
		philo->meals++;
		if (!philo->stage)
			return (0);
		ft_update_date(&philo->last_sleep, &philo->info->current);
		ft_print_status(philo, "is sleeping");
		while (philo->stage == 2 && ft_philo_sleep(philo))
			usleep(500);
		if (!philo->stage)
			return (0);
	}
	return (0);
}

int	ft_forks_choice(t_philo *philo, int lock)
{
	if (philo->id % 2 == 0 && !philo->meals)
		usleep(150);
	if (lock && philo->r_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork);
		ft_print_status(philo, "has taken a fork");
	}
	else if (!lock && philo->r_fork)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	if (!philo->r_fork)
		return (ft_one_fork(philo));
	return (1);
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

void	ft_initialize_philos(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		philos[i].id = i + 1;
		philos[i].stage = 1;
		philos[i].meals = 0;
		philos[i].info = info;
		philos[i].r_fork = 1;
		ft_update_date(&philos[i].last_meal, &info->start);
		ft_update_date(&philos[i].last_sleep, &info->start);
		if ((i + 1) < info->total_philos)
			philos[i].right_fork = &philos[i + 1].left_fork;
		else if (info->total_philos > 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].r_fork = 0;
		pthread_create(&philos[i].thread, 0, ft_philo_logic, &philos[i]);
		i++;
	}
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
