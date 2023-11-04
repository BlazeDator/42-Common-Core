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
int count;


void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("0", count);
		count++;
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("1", count);
		count++;
	}
	if (count == 8)
	{
		ft_printf("\n");
		count = 0;
	}
}

static void	set_signal_action(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(action));
	action.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
}

int	main(void)
{
	pid_t	pid;

	count = 0;
	pid = getpid();
	set_signal_action();
	ft_printf("PID: %i\n", pid);
	while (1)
		continue ;
	return (0);
}
