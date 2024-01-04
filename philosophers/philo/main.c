/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:12 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/04 11:15:51 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  
number of times each philosopher must eat:
If not specified, the simulation stops when a philosopher dies.


	TODO: Only 1 philo crashes, needs fix 
*/

void	ft_cleanup(t_philo *philos, t_info *info);
void	ft_showtime(void);

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
		ft_current_time(&info);
	ft_destroy_philos(philos, &info);
	ft_destroy_forks(philos, &info);
	free(philos);
	return (0);
}

void	ft_cleanup(t_philo *philos, t_info *info)
{
	ft_destroy_philos(philos, info);
	printf("All threads are deleted\n");
	ft_destroy_forks(philos, info);
	free(philos);
}

void	ft_showtime(void)
{
	struct timeval	teste;

	gettimeofday(&teste, 0);
	printf("Seconds: %li, Microseconds: %li\n", teste.tv_sec, teste.tv_usec);
}
