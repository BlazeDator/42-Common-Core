/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 12:42:35 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_status(t_philo *philo, char *str);

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->threads_mutex);
	pthread_mutex_unlock(&philo->info->threads_mutex);
	ft_start_dates(philo, philo->info);
	while (ft_read_stage(philo->info))
	{
		ft_print_status(philo, "hii");
		pthread_mutex_lock(&philo->eating);
		philo->meals++;
		pthread_mutex_unlock(&philo->eating);
		usleep(1000000);
	}
	return (0);
}


static void	ft_print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->time_mutex);
	printf("%i %i %s\n", 
		ft_diff_ms(&philo->info->current, &philo->info->start), 
		philo->id,
		str); 
	pthread_mutex_unlock(&philo->info->time_mutex);
}
