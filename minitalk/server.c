/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/03 16:03:45 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	Only use SIGUSR1 and SIGUSR2
*/

void	sigusr1_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\nOla to you too!\n");
}

void	set_signal_action(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(action));
	action.sa_handler = &sigusr1_handler;
	sigaction(SIGUSR1, &action, 0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	set_signal_action();
	ft_printf("PID: %i\n", pid);
	while (1)
		continue ;
	return (0);
}
