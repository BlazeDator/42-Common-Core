/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:53 by pabernar          #+#    #+#             */
/*   Updated: 2023/12/19 12:41:20 by pabernar         ###   ########.fr       */
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
typedef struct s_info
{
	int	total_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_to_eat;
}		t_info;

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
/*				debug.c					      */
/* ************************************************************************** */
void	ft_display_info(t_info *info);
#endif
