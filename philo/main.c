/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:38:44 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 15:06:23 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_print_format(void);
static void	ft_time_keeper(t_info *info, t_philo *philos);
static int	ft_check_meals(t_info *info, t_philo *philos);
static int	ft_check_death(t_info *info, t_philo *philos);

int	main(int argc, char **argv)
{
	t_info			info;
	t_philo			*philos;

	info.stage = 1;
	if (argc < 5 || argc > 6)
		return (ft_print_format());
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Invalid Arguments\n"));
	philos = malloc(sizeof(t_philo) * info.total_philos);
	if (!philos)
		return (0);
	if (ft_init_mutexes(philos, &info))
	{
		pthread_mutex_lock(&info.threads_mutex);
		if (ft_init_philos(philos, &info))
		{
			ft_time_keeper(&info, philos);
			ft_destroy_philos(philos, &info);
		}
		else
			pthread_mutex_unlock(&info.threads_mutex);
		ft_destroy_mutexes(philos, &info);
	}
	free(philos);
	return (0);
}

static int	ft_print_format(void)
{
	return (printf("./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep>\
 <number_of_times_each_philosopher_must_eat>\n"));
}

static void	ft_time_keeper(t_info *info, t_philo *philos)
{
	while (gettimeofday(&info->start, 0)
		|| gettimeofday(&info->current, 0))
		continue ;
	pthread_mutex_unlock(&info->threads_mutex);
	while (ft_read_stage(info))
	{
		usleep(500);
		pthread_mutex_lock(&info->time_mutex);
		while (gettimeofday(&info->current, 0))
			continue ;
		pthread_mutex_unlock(&info->time_mutex);
		if (info->times_to_eat && ft_check_meals(info, philos))
			break ;
		if (ft_check_death(info, philos))
			break ;
	}
}

static int	ft_check_meals(t_info *info, t_philo *philos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < info->total_philos)
	{
		pthread_mutex_lock(&philos[i].eating);
		if (philos[i].meals >= info->times_to_eat)
			count++;
		pthread_mutex_unlock(&philos[i].eating);
		i++;
	}
	i = 0;
	if (count == info->total_philos)
	{
		ft_set_stage(info);
		return (1);
	}
	return (0);
}

static int	ft_check_death(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->total_philos)
	{
		if (!pthread_mutex_lock(&philos[i].info->time_mutex)
			&& ft_diff_ms(&philos[i].last_meal, &info->current) 
			>= info->time_die)
		{
			pthread_mutex_unlock(&philos[i].info->time_mutex);
			ft_print_status(&philos[i], "died");
			ft_set_stage(info);
			return (1);
		}
		i++;
	}
	return (0);
}
