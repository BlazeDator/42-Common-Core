/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:26:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 14:42:08 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_three(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*b))
	{
		ft_calc_targets_three(*b, *a);
		if ((*b)->target == (*a)->number)
		{
			ft_stack_push(a, b);
			ft_printf("pa\n");
			continue ;
		}
		ft_calc_push_cost_one(*b, *a);
		ft_move_cheap_b(b, a, 
			ft_lowest_cost(*b),
			ft_stack_target(*b, ft_lowest_cost(*b)));
		ft_stack_push(a, b);
		ft_printf("pa\n");
	}
}

void	ft_move_cheap_b(t_stack **a, t_stack **b, int cheap, int target)
{
	while (ft_stack_pos(*a, cheap) != 0 
		|| ft_stack_pos(*b, target) != 0)
	{
		ft_rot_phase_b(a, b, cheap, target);
		ft_rev_phase_b(a, b, cheap, target);
	}
}

void	ft_rot_phase_b(t_stack **a, t_stack **b, int cheap, int target)
{
	if (ft_behind_median(*a, cheap)
		&& ft_behind_median(*b, target)
		&& ft_stack_pos(*a, cheap) > 0
		&& ft_stack_pos(*b, target) > 0)
	{
		*a = ft_stack_rotate(*a);
		*b = ft_stack_rotate(*b);
		ft_printf("rr\n");
	}
	else if (ft_behind_median(*a, cheap) && ft_stack_pos(*a, cheap) > 0)
	{
		*a = ft_stack_rotate(*a);
		ft_printf("rb\n");
	}
	else if (ft_behind_median(*b, target) && ft_stack_pos(*b, target) > 0)
	{
		*b = ft_stack_rotate(*b);
		ft_printf("ra\n");
	}
}

void	ft_rev_phase_b(t_stack **a, t_stack **b, int cheap, int target)
{
	if (!ft_behind_median(*a, cheap)
		&& !ft_behind_median(*b, target)
		&& ft_stack_pos(*a, cheap) > 0
		&& ft_stack_pos(*b, target) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		*b = ft_stack_reverse_rotate(*b);
		ft_printf("rrr\n");
	}
	else if (!ft_behind_median(*a, cheap) && ft_stack_pos(*a, cheap) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		ft_printf("rrb\n");
	}
	else if (!ft_behind_median(*b, target) && ft_stack_pos(*b, target) > 0)
	{
		*b = ft_stack_reverse_rotate(*b);
		ft_printf("rra\n");
	}
}
