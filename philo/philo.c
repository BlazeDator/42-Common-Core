/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 10:43:06 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->threads_mutex);
	ft_start_dates(philo, philo->info);
	pthread_mutex_unlock(&philo->info->threads_mutex);
	while (ft_read_stage(philo->info))
	{

	}
	return (0);
}

int	ft_read_stage(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->stage_mutex);
	i = info->stage;	
	pthread_mutex_unlock(&info->stage_mutex);
	return (i);
}

void	ft_print_status(t_philo *philo, char *str)
{
	if (ft_read_stage(philo))
		printf("%i %i %s\n", 
			ft_diff_ms(&philo->info->current, &philo->info->start), 
			philo->id,
			str); 
}
