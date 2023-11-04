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

int	main(int argc, char **argv)
{
	pid_t	pid;
	unsigned char	bits[8];
	int i = 0;
	int j = 0;

	ft_bzero(bits, 8);
	if (argc != 3)
		return (ft_printf("Usage: client PID string"));
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (ft_printf("Error: Invalid PID"));
	while (j < 5)
	{
		ft_byte_to_bits(argv[2][j], &bits[7]);
		while (i < 8)
		{
			ft_printf("%i", bits[i]);
			i++;
		}
		ft_printf("\n");
		j++;
		i = 0;
		ft_bzero(bits, 8);
	}
	// kill(pid, SIGUSR1);
	return (0);
}
