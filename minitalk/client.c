/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:27 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/03 12:41:28 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_string(char *str, pid_t pid)
{
	unsigned char	bits[8];
	int				i;
	int				j;

	i = 0;
	ft_bzero(bits, 8);
	while (str[i])
	{
		j = 0;
		ft_byte_to_bits(str[i], &bits[7]);
		while (j < 8)
		{
			if (bits[j] == 0)
				kill(pid, SIGUSR1);
			else if (bits[j] == 1)
				kill(pid, SIGUSR2);
			usleep(1);
			j++;
		}
		ft_bzero(bits, 8);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("Usage: client PID string"));
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (ft_printf("Error: Invalid PID"));
	ft_send_string(argv[2], pid);
	return (0);
}
