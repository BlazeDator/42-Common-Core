/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:19:33 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 10:27:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_one(t_stack **a, t_stack **b, char **commands)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_calc_targets_one(*a, *b);
		if ((*a)->target == (*b)->number)
		{
			ft_stack_push(b, a);
			*commands = ft_strjoin_f(*commands, "pb\n");
			continue ;
		}
		ft_calc_push_cost_one(*a, *b);
		ft_move_cheapest(a, b, ft_lowest_cost(*a), commands);
		ft_stack_push(b, a);
		*commands = ft_strjoin_f(*commands, "pb\n");
	}
}

void	ft_move_cheapest(t_stack **a, t_stack **b, int cheap, char **commands)
{
	while (ft_stack_pos(*a, cheap) != 0 
		|| ft_stack_pos(*b, ft_stack_target(*a, cheap)) != 0)
	{
		ft_rot_phase_one(a, b, cheap, commands);
		ft_rev_phase_one(a, b, cheap, commands);
	}
}

void	ft_rot_phase_one(t_stack **a, t_stack **b, int cheap, char **commands)
{
	if (ft_behind_median(*a, cheap)
		&& ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*a, cheap) > 0
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*a = ft_stack_rotate(*a);
		*b = ft_stack_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rr\n");
	}
	else if (ft_behind_median(*a, cheap) && ft_stack_pos(*a, cheap) > 0)
	{
		*a = ft_stack_rotate(*a);
		*commands = ft_strjoin_f(*commands, "ra\n");
	}
	else if (ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*b = ft_stack_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rb\n");
	}
}

void	ft_rev_phase_one(t_stack **a, t_stack **b, int cheap, char **commands)
{
	if (!ft_behind_median(*a, cheap)
		&& !ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*a, cheap) > 0
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		*b = ft_stack_reverse_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rrr\n");
	}
	else if (!ft_behind_median(*a, cheap) && ft_stack_pos(*a, cheap) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		*commands = ft_strjoin_f(*commands, "rra\n");
	}
	else if (!ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*b = ft_stack_reverse_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rrb\n");
	}
}
