/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dates.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:31:01 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 12:57:05 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_update_date(t_timeval *dest, t_timeval *src);

void	ft_start_dates(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->time_mutex);
	ft_update_date(&philo->last_meal, &info->start);
	ft_update_date(&philo->last_sleep, &info->start);
	pthread_mutex_unlock(&info->time_mutex);
}

static void	ft_update_date(t_timeval *dest, t_timeval *src)
{
	dest->tv_sec = src->tv_sec;
	dest->tv_usec = src->tv_usec;
}
