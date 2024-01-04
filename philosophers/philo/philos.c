/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:57:40 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/04 11:22:14 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forks_choice(t_philo *philo, int lock);

void	*ft_philo_logic(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (philo->stage != 0)
	{
		ft_forks_choice(philo, 1);
		ft_update_date(&philo->last_meal, &philo->info->current);
		ft_print_status(philo, "is eating");
		philo->meals++;
		while (philo->stage == 1 && ft_philo_eat(philo))
			continue ;
		if (!philo->stage)
			return (0);
		ft_forks_choice(philo, 0);
		ft_update_date(&philo->last_sleep, &philo->info->current);
		ft_print_status(philo, "is sleeping");
		while (philo->stage == 2 && ft_philo_sleep(philo))
			continue ;
		if (!philo->stage)
			return (0);
		ft_print_status(philo, "is thinking");
		usleep(100);
	}
	return (0);
}

void	ft_forks_choice(t_philo *philo, int lock)
{
	if (philo->id % 2 == 0 && lock)
	{
		pthread_mutex_lock(&philo->left_fork);
		printf("%i %i has taken a fork\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), philo->id); 
		pthread_mutex_lock(philo->right_fork);
		printf("%i %i has taken a fork\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), philo->id); 
	}
	else if (philo->id % 2 == 1 && lock)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%i %i has taken a fork\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), philo->id); 
		pthread_mutex_lock(&philo->left_fork);
		printf("%i %i has taken a fork\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), philo->id); 
	}
	else if (!lock)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
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
		if ((i + 1) < info->total_philos)
			philos[i].right_fork = &philos[i + 1].left_fork;
		else if (info->total_philos > 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].right_fork = 0;
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
		printf("Deleting Philo %i\n", i + 1);
		i++;
	}
}
