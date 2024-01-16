/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:14:55 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 12:15:20 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_read_stage(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->stage_mutex);
	i = info->stage;
	pthread_mutex_unlock(&info->stage_mutex);
	return (i);
}

void	ft_set_stage(t_info *info)
{
	pthread_mutex_lock(&info->stage_mutex);
	info->stage = 0;
	pthread_mutex_unlock(&info->stage_mutex);
}
