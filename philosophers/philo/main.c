/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:12 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/04 14:45:57 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	TODO: Make sure everytime gettimeofday is called, 
	check for errors and maybe dont update the date
	RETURN VALUE
       gettimeofday() and settimeofday() return 0 for success.  On
       error, -1 is returned and errno is set to indicate the error.
*/

void	ft_cleanup(t_philo *philos, t_info *info);
int		ft_check_philos(t_philo *philos, t_info *info);

int	main(int argc, char **argv)
{
	t_info			info;
	t_philo			*philos;

	if (argc < 5 || argc > 6)
		return (ft_print_format());
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Invalid Arguments\n"));
	gettimeofday(&info.start, 0);
	gettimeofday(&info.current, 0);
	philos = malloc(sizeof(t_philo) * info.total_philos);
	ft_initialize_forks(philos, &info);
	ft_initialize_philos(philos, &info);
	while (1)
	{
		ft_current_time(&info);
		if (!ft_check_philos(philos, &info))
			break ;
	}
	ft_cleanup(philos, &info);
	return (0);
}

void	ft_cleanup(t_philo *philos, t_info *info)
{
	ft_destroy_philos(philos, info);
	ft_destroy_forks(philos, info);
	free(philos);
}

int	ft_check_philos(t_philo *philos, t_info *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < info->total_philos)
	{
		if (ft_diff_ms(&philos[i].last_meal, &info->current) 
			> info->time_die)
		{
			ft_print_status(&philos[i], "died");
			i = 0;
			while (i < info->total_philos)
				ft_set_stage(&philos[i++], 0);
			return (0);
		}
		if (info->times_to_eat 
			&& philos[i].meals >= info->times_to_eat && ++count)
			ft_set_stage(&philos[i], 0);
		i++;
	}
	if (count == info->total_philos)
		return (0);
	return (1);
}
