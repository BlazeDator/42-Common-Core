/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 16:13:57 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  
number of times each philosopher must eat:
If not specified, the simulation stops when a philosopher dies. 
*/

void	ft_cleanup(int *numbers, pthread_t *philos, 
			pthread_mutex_t *forks, t_info *info);
void	ft_showtime(void);

int	main(int argc, char **argv)
{
	t_info			info;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				i;
	int				*numbers;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep>\
 <number_of_times_each_philosopher_must_eat>\n"));
	if (!ft_check_arguments(argc, argv, &info))
		return (printf("Error: Invalid Arguments (integers >= 0)\n"));
	ft_display_info(&info);
	philos = malloc(sizeof(pthread_t) * info.total_philos);
	forks = malloc(sizeof(pthread_mutex_t) * info.total_philos);
	numbers = malloc(sizeof(int) * info.total_philos);
	if (!ft_initialize_forks(forks, &info))
		return (printf("Error: Mutex inits failed"));
	ft_initialize_philos(philos, &info, numbers);
	printf("All threads created\n");
	ft_cleanup(numbers, philos, forks, &info);
	ft_showtime();
	return (0);
}

void	ft_cleanup(int *numbers, pthread_t *philos, 
			pthread_mutex_t *forks, t_info *info)
{
	ft_destroy_philos(philos, info);
	printf("All threads are deleted\n");
	ft_destroy_forks(forks, info);
	free(numbers);
	free(philos);
	free(forks);
}

void	ft_showtime(void)
{
	struct timeval	teste;

	gettimeofday(&teste, 0);
	printf("Seconds: %li, Microseconds: %li\n", teste.tv_sec, teste.tv_usec);
}
