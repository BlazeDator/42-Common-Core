/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 11:46:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  
number of times each philosopher must eat:
If not specified, the simulation stops when a philosopher dies. 
*/
int	main(int argc, char **argv)
{
	t_info			info;
	pthread_t		*philos;
	pthread_mutex_t	*forks;

	if (argc < 5 || argc > 6)
		return (printf("./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep>\
 <number_of_times_each_philosopher_must_eat>\n"));
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Arguments aren't integers (>= 0)"));
	printf("Philos: %i\n", info.total_philos);
	printf("Time to die: %i\n", info.time_die);
	printf("Time to eat: %i\n", info.time_eat);
	printf("Time to sleep: %i\n", info.time_sleep);
	printf("Times to eat: %i\n", info.times_to_eat);
	philos = malloc(sizeof(pthread_t) * 1);
	forks = malloc(sizeof(pthread_mutex_t) * 1);
	return (0);
}
