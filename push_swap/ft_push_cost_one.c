/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_cost_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:05:36 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/20 14:17:10 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_cost_a(t_stack *a_start, t_stack *a);
static void	ft_push_cost_b(t_stack *b_start, t_stack *a);

void	ft_calc_push_cost_one(t_stack *a, t_stack *b)
{
	t_stack	*a_start;
	t_stack	*b_start;

	a_start = a;
	b_start = b;
	while (a)
	{
		a->push_cost = 0;
		ft_push_cost_a(a_start, a);
		ft_push_cost_b(b_start, a);
		if (ft_behind_median(a_start, a->number) 
			&& ft_behind_median(b_start, a->target))
			a->push_cost = a->push_cost
				- ft_min(ft_stack_pos(a_start, a->number),
					ft_stack_pos(b_start, a->target));
		if (!ft_behind_median(a_start, a->number)
			&& !ft_behind_median(b_start, a->target))
			a->push_cost = a->push_cost
				- ft_min(ft_stack_size(a_start) 
					- ft_stack_pos(a_start, a->number),
					ft_stack_size(b_start) 
					- ft_stack_pos(b_start, a->target)); 
		a = a->next;
	}
}

static void	ft_push_cost_a(t_stack *a_start, t_stack *a)
{
	if (ft_behind_median(a_start, a->number))
		a->push_cost += ft_stack_pos(a_start, a->number);
	else
		a->push_cost = a->push_cost
			+ (ft_stack_size(a_start)
				- ft_stack_pos(a_start, a->number));
}

static void	ft_push_cost_b(t_stack *b_start, t_stack *a)
{
	if (ft_behind_median(b_start, a->target))
		a->push_cost = a->push_cost
			+ ft_stack_pos(b_start, a->target);
	else
		a->push_cost = a->push_cost
			+ (ft_stack_size(b_start)
				- ft_stack_pos(b_start, a->target));
}
