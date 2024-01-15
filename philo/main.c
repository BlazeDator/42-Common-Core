/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:38:44 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 15:25:28 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	TODO:
		Implement all the functions on main
*/
static int	ft_print_format(void);

int	main(int argc, char **argv)
{
	t_info			info;
	t_philo			*philos;

	if (argc < 5 || argc > 6)
		return (ft_print_format());
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Invalid Arguments\n"));
	philos = malloc(sizeof(t_philo) * info.total_philos);
	if (!philos)
		return (0);
	ft_init_mutexes(philos, &info);
	ft_init_philos(philos, &info);
	ft_time_keeper(philos, &info);
	ft_destroy_philos(philos, &info);
	ft_destroy_mutexes(philos, &info);
	free(philos);
	return (0);
}

static int	ft_print_format(void)
{
	return (printf("./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep>\
 <number_of_times_each_philosopher_must_eat>\n"));
}
