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

	if (argc != 3)
		return (ft_printf("Usage: client PID string"));
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (ft_printf("Error: Invalid PID"));
	kill(pid, SIGUSR1);
	return (0);
}
