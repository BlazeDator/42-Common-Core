/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:26:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 12:35:50 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_three(t_stack **a, t_stack **b, char **commands)
{
	while (ft_stack_size(*b))
	{
		ft_calc_targets_three(*b, *a);
		if ((*b)->target == (*a)->number)
		{
			ft_stack_push(a, b);
			*commands = ft_strjoin_f(*commands, "pa\n");
			continue ;
		}
		ft_calc_push_cost_one(*b, *a);
		ft_move_cheap_b(b, a, ft_lowest_cost(*b), commands);
		ft_stack_push(a, b);
		*commands = ft_strjoin_f(*commands, "pa\n");
	}
}

void	ft_move_cheap_b(t_stack **a, t_stack **b, int cheap, char **commands)
{
	while (ft_stack_pos(*a, cheap) != 0 
		|| ft_stack_pos(*b, ft_stack_target(*a, cheap)) != 0)
	{
		ft_rot_phase_b(a, b, cheap, commands);
		ft_rev_phase_b(a, b, cheap, commands);
	}
}

void	ft_rot_phase_b(t_stack **a, t_stack **b, int cheap, char **commands)
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
		*commands = ft_strjoin_f(*commands, "rb\n");
	}
	else if (ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*b = ft_stack_rotate(*b);
		*commands = ft_strjoin_f(*commands, "ra\n");
	}
}

void	ft_rev_phase_b(t_stack **a, t_stack **b, int cheap, char **commands)
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
		*commands = ft_strjoin_f(*commands, "rrb\n");
	}
	else if (!ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*b = ft_stack_reverse_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rra\n");
	}
}
