/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:23:15 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/20 10:02:28 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_targets_one(t_stack *a, t_stack *b)
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
