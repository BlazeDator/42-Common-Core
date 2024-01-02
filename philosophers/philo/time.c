/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:47:31 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/02 10:58:42 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_diff_ms(t_timeval *first, t_timeval *second)
{
	int	sum;

	sum = 0;
	sum += ft_abs(first->tv_sec - second->tv_sec) * 1000;
	sum += ft_abs(first->tv_usec - second->tv_usec) / 1000;
	return (sum);
}
