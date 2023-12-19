/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:13:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  
number of times each philosopher must eat:
If not specified, the simulation stops when a philosopher dies. 
*/

void	*say_hi(void *i)
{
	int	*x;

	x = (int *)i;
	printf("Thread %i: hi!\n", *x);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info			info;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep>\
 <number_of_times_each_philosopher_must_eat>\n"));
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Arguments aren't integers (>= 0)\n"));
	ft_display_info(&info);
	philos = malloc(sizeof(pthread_t) * info.total_philos);
	forks = malloc(sizeof(pthread_mutex_t) * info.total_philos);
	int	numbers[info.total_philos];
	while (i < info.total_philos)
	{
		numbers[i] = i;
		printf("Starting Thread %i\n", i);
		pthread_create(&philos[i], 0, say_hi, &numbers[i]);
		i++;
	}
	printf("All threads created\n");
	i = 0;
	while (i < info.total_philos)
	{
		pthread_join(philos[i], 0);
		printf("Deleting Thread %i\n", i);
		i++;
	}
	printf("All threads are deleted\n");
	free(philos);
	free(forks);
	return (0);
}
