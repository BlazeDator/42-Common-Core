/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase_one_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:38:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 15:19:42 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_one_calc_value(t_node *node)
{
	while (node)
	{
		ft_phase_one_calc_targets(node->a, node->b);
		node->value = ft_phase_one_stacks_value(node->a, node->b);
		node = node->next;
	}
}

int	ft_phase_one_stacks_value(t_stack *a, t_stack *b)
{
	int	value;

	value = 0;
	while (a && a->next)
	{
		if (a->number < a->next->number)
			value += 1;
		a = a->next;
	}
	while (b && b->next)
	{
		if (b->target == b->next->number && b->target != 0)
			value += 4;
		if (b->number > b->next->number && b->target == 0)
			value += 2;
		b = b->next;
	}
	value += ft_stack_size(b);
	return (value);
}
/*
	Assuming a and b has numbers
*/

void	ft_phase_one_calc_targets(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	int		max;

	temp = b;
	max = b->number;
	while (a)
	{
		a->target = a->number;
		while (b)
		{
			if (b->number > max)
				max = b->number;
			if ((b->number < a->target && a->target == a->number)
				|| (b->number > a->target && b->number < a->number
					&& a->target != a->number))
				a->target = b->number;
			b = b->next;
		}
		if (a->target == a->number)
			a->target = max;
		b = temp;
		a = a->next;
	}
}
