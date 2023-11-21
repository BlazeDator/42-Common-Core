/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:06:02 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 11:00:27 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_stack *a)
{
	t_stack	*b;
	char	*commands;

	b = 0;
	commands = malloc(1);
	if (!commands)
		return ;
	commands[0] = '\0';
	while (ft_stack_size(a) > 3 && ft_stack_size(b) < 2)
	{
		ft_stack_push(&b, &a);
		commands = ft_strjoin_f(commands, "pb\n");
	}
	ft_phase_one(&a, &b, &commands);
	ft_phase_two(&a, &commands);
	ft_stack_display(a);
	ft_stack_display(b);
	ft_targets_display(a);
	a = ft_stack_free(a);
	b = ft_stack_free(b);
	ft_printf(commands);
	free(commands);
}
