/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:06:02 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 13:01:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
837 640 863 668 406 485 559 305 673 424 937 457 808 943 388
*/

static void	ft_order(t_stack **a, char **commands);

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
	ft_phase_three(&a, &b, &commands);
	ft_order(&a, &commands);
	ft_printf(commands);
	//ft_stack_display(a);
	//ft_stack_display(b);
	a = ft_stack_free(a);
	b = ft_stack_free(b);
	free(commands);
}

static void	ft_order(t_stack **a, char **commands)
{
	t_stack	*traveler;
	int		min;

	min = (*a)->number;
	traveler = *a;
	while (traveler)
	{
		if (traveler->number < min)
			min = traveler->number;
		traveler = traveler->next;
	}
	while (ft_behind_median(*a, min) && ft_stack_pos(*a, min) > 0)
	{
		*a = ft_stack_rotate(*a);
		*commands = ft_strjoin_f(*commands, "ra\n");
	}
	while (!ft_behind_median(*a, min) && ft_stack_pos(*a, min) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		*commands = ft_strjoin_f(*commands, "rra\n");
	}
}
