/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:00:28 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/01 14:27:56 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_executer(char *path)
{
	char	**test;

	test = 0;
	if (fork() == 0)
	{
		ft_restore_signals();
		execve(path, test, test);
		exit(0);
	}
	ft_ignore_signals();
	wait(0);
	if (g_signal == SIGINT)
		printf("\n");
	rl_on_new_line();
	ft_init_signals();
}
