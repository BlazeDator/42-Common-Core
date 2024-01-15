/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:37:30 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 12:40:04 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_display_info(t_info *info)
{
	printf("Philos: %i\n", info->total_philos);
	printf("Time to die: %i\n", info->time_die);
	printf("Time to eat: %i\n", info->time_eat);
	printf("Time to sleep: %i\n", info->time_sleep);
	printf("Times to eat: %i\n", info->times_to_eat);
}
