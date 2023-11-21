/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:19:33 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 15:47:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_one(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_calc_targets_one(*a, *b);
		ft_calc_push_cost_one(*a, *b);
		if ((*a)->target == (*b)->number)
		{
			ft_stack_push(b, a);
			ft_printf("pb\n");
			continue ;
		}
		ft_move_cheapest(a, b,
			ft_lowest_cost(*a),
			ft_stack_target(*a, ft_lowest_cost(*a)));
		ft_stack_push(b, a);
		ft_printf("pb\n");
	}
}

void	ft_move_cheapest(t_stack **a, t_stack **b, int cheap, int target)
{
	while (ft_stack_pos(*a, cheap) != 0
		|| ft_stack_pos(*b, target) != 0)
	{
		ft_rot_phase_one(a, b, cheap, target);
		ft_rev_phase_one(a, b, cheap, target);
	}
}

void	ft_rot_phase_one(t_stack **a, t_stack **b, int cheap, int target)
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
		ft_printf("ra\n");
	}
	else if (ft_behind_median(*b, target) && ft_stack_pos(*b, target) > 0)
	{
		*b = ft_stack_rotate(*b);
		ft_printf("rb\n");
	}
}

void	ft_rev_phase_one(t_stack **a, t_stack **b, int cheap, int target)
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
		ft_printf("rra\n");
	}
	else if (!ft_behind_median(*b, target) && ft_stack_pos(*b, target) > 0)
	{
		*b = ft_stack_reverse_rotate(*b);
		ft_printf("rrb\n");
	}
}
