/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:42:17 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/01 10:28:09 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_handle_sigint(int sig);

void	ft_init_signals(void)
{
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_handle_eof(void)
{
	rl_replace_line("exit", 0);
	rl_redisplay();
	printf("\n");
	ft_exit();
}

void	ft_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}
