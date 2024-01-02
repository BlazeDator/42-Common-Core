/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:53 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/02 10:13:16 by pabernar         ###   ########.fr       */
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
	int			total_philos;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			times_to_eat;
	t_timeval	start;
	t_timeval	current;
}		t_info;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	stage_mutex;
	t_info			*info;
	int				id;
	int				stage;
	int				meals;
	t_timeval		last_meal;
	t_timeval		last_sleep;
}		t_philo;

/* ************************************************************************** */
/*				philos.c				      */
/* ************************************************************************** */
void	ft_initialize_philos(pthread_t *philos, t_info *info, int *numbers);
void	ft_destroy_philos(pthread_t *philos, t_info *info);
/* ************************************************************************** */
/*				forks.c					      */
/* ************************************************************************** */
int		ft_initialize_forks(pthread_mutex_t *forks, t_info *info);
void	ft_destroy_forks(pthread_mutex_t *forks, t_info *info);
/* ************************************************************************** */
/*				arguments.c				      */
/* ************************************************************************** */
int		ft_check_atoi(int num, char *str);
int		ft_check_arguments(int argc, char **argv, t_info *info);
/* ************************************************************************** */
/*				helpers.c				      */
/* ************************************************************************** */
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_itoalen(int n);
char	*ft_itoa(int n);
/* ************************************************************************** */
/*				helpers_extra.c				      */
/* ************************************************************************** */
int		ft_abs(int num);
/* ************************************************************************** */
/*				debug.c					      */
/* ************************************************************************** */
void	ft_display_info(t_info *info);
#endif
