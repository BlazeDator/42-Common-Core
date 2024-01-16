/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:53 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/16 14:59:27 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

/* ************************************************************************** */
/*				structs					      */
/* ************************************************************************** */
typedef struct timeval	t_timeval;

typedef struct s_info
{
	pthread_mutex_t	threads_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	stage_mutex;
	int				total_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	int				stage;
	t_timeval		start;
	t_timeval		current;
}		t_info;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	eating;
	t_info			*info;
	int				id;
	int				meals;
	int				r_fork;
	t_timeval		last_meal;
	t_timeval		last_sleep;
}		t_philo;
/* ************************************************************************** */
/*				mutexes.c				      */
/* ************************************************************************** */
int		ft_init_mutexes(t_philo *philos, t_info *info);
void	ft_destroy_mutexes(t_philo *philos, t_info *info);
/* ************************************************************************** */
/*				philos_init.c				      */
/* ************************************************************************** */
int		ft_init_philos(t_philo *philos, t_info *info);
void	ft_destroy_philos(t_philo *philos, t_info *info);
/* ************************************************************************** */
/*				philo.c					      */
/* ************************************************************************** */
void	*ft_philo(void *data);
void	ft_print_status(t_philo *philo, char *str);
/* ************************************************************************** */
/*				forks.c					      */
/* ************************************************************************** */
int	ft_take_forks(t_philo *philo);
/* ************************************************************************** */
/*				stage.c					      */
/* ************************************************************************** */
int		ft_read_stage(t_info *info);
void	ft_set_stage(t_info *info);
/* ************************************************************************** */
/*				dates.c					      */
/* ************************************************************************** */
void	ft_start_dates(t_philo *philo, t_info *info);
void	ft_meal_date(t_philo *philo, t_info *info);
void	ft_sleep_date(t_philo *philo, t_info *info);
/* ************************************************************************** */
/*				time.c					      */
/* ************************************************************************** */
int		ft_diff_ms(t_timeval *first, t_timeval *second);
/* ************************************************************************** */
/*				arguments.c				      */
/* ************************************************************************** */
int		ft_check_arguments(int argc, char **argv, t_info *info);
/* ************************************************************************** */
/*				helpers.c				      */
/* ************************************************************************** */
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
/* ************************************************************************** */
/*				debug.c					      */
/* ************************************************************************** */
void	ft_display_info(t_info *info);
#endif
