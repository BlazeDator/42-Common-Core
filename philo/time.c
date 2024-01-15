/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:47:31 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 11:23:56 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_abs(int num);

int	ft_diff_ms(t_timeval *first, t_timeval *second)
{
	int	sum;

	sum = 0;
	sum += (first->tv_sec - second->tv_sec) * 1000;
	sum += (first->tv_usec - second->tv_usec) / 1000;
	return (ft_abs(sum));
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
