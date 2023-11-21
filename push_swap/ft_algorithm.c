/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:06:02 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 09:26:01 by pabernar         ###   ########.fr       */
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
		commands = ft_strjoin_f(commands, "pa\n");
	}
	ft_phase_one(&a, &b, &commands);
	ft_stack_display(a);
	ft_stack_display(b);
	ft_targets_display(a);
	a = ft_stack_free(a);
	b = ft_stack_free(b);
	ft_printf(commands);
	free(commands);
}

void	ft_phase_one(t_stack **a, t_stack **b, char **commands)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_calc_targets_one(*a, *b);
		if ((*a)->target == (*b)->number)
		{
			ft_stack_push(b, a);
			*commands = ft_strjoin_f(*commands, "pa\n");
			continue ;
		}
		ft_calc_push_cost_one(*a, *b);
		ft_move_cheapest(a, b, ft_lowest_cost(*a), commands);
		ft_stack_push(b, a);
		*commands = ft_strjoin_f(*commands, "pa\n");
		break ;
	}
}

void	ft_move_cheapest(t_stack **a, t_stack **b, int cheap, char **commands)
{
	while (ft_stack_pos(*a, cheap) != 0 
		|| ft_stack_pos(*b, ft_stack_target(*a, cheap)) != 0)
	{
		ft_rot_phase_one(a, b, cheap, commands);
	}
}
/*ft_printf("cheap: %i target: %i position: %i behind_median:%i\n",
		cheap , 
		ft_stack_target(*a, cheap),
		ft_stack_pos(*b, ft_stack_target(*a, cheap)), 
		ft_behind_median(*b, ft_stack_target(*a, cheap)));
*/
