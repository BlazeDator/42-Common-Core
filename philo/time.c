/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:47:31 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 11:19:31 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_abs(int num);

int	ft_diff_ms(t_timeval *first, t_timeval *second)
{
	int	seconds;
	int	microseconds;

	seconds = (first->tv_sec - second->tv_sec) * 1000;
	microseconds = (first->tv_usec - second->tv_usec) / 1000;
	return (ft_abs(seconds + microseconds));
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
