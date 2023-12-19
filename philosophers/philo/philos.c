/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:57:40 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 15:08:54 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*say_hi(void *i)
{
	int	*x;

	x = (int *)i;
	printf("Thread %i: hi!\n", *x);
	return (0);
}

void	ft_initialize_philos(pthread_t *philos, t_info *info, int *numbers)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		numbers[i] = i;
		printf("Starting Thread %i\n", i);
		pthread_create(&philos[i], 0, say_hi, &numbers[i]);
		i++;
	}
}

void	ft_destroy_philos(pthread_t *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		pthread_join(philos[i], 0);
		printf("Deleting Thread %i\n", i);
		i++;
	}
}
