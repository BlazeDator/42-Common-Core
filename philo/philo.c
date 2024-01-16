/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:16 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 11:51:23 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_read_stage(t_info *info);
static void	ft_print_status(t_philo *philo, char *str);

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->threads_mutex);
	ft_start_dates(philo, philo->info);
	ft_print_status(philo, "Updated dates");
	pthread_mutex_unlock(&philo->info->threads_mutex);
	while (ft_read_stage(philo->info))
	{
		ft_print_status(philo, "hii");
		usleep(1000000);
	}
	return (0);
}

static int	ft_read_stage(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->stage_mutex);
	i = info->stage;
	pthread_mutex_unlock(&info->stage_mutex);
	return (i);
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
