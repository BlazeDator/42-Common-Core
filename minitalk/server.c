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

void	signal_handler(int signal)
{
	static int	count;
	static char	bits[8];

	if (signal == SIGUSR1)
		bits[count++] = 0;
	else if (signal == SIGUSR2)
		bits[count++] = 1;
	if (count == 8)
	{
		count = 0;
		ft_printf("%c", ft_bits_to_byte(bits));
		ft_bzero(bits, 8);
	}
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_bzero(&action, sizeof(action));
	action.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ft_printf("PID: %i\n", pid);
	while (1)
		continue ;
	return (0);
}
