/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:06:02 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 14:03:24 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
837 640 863 668 406 485 559 305 673 424 937 457 808 943 388
*/

static void	ft_order(t_stack **a);

void	ft_algorithm(t_stack *a)
{
	t_stack	*b;

	b = 0;
	while (ft_stack_size(a) > 3 && ft_stack_size(b) < 2)
	{
		ft_stack_push(&b, &a);
		ft_printf("pb\n");
	}
	ft_phase_one(&a, &b);
	ft_phase_two(&a);
	ft_phase_three(&a, &b);
	ft_order(&a);
	//ft_stack_display(a);
	//ft_stack_display(b);
	a = ft_stack_free(a);
	b = ft_stack_free(b);
}

static void	ft_order(t_stack **a)
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
		ft_printf("ra\n");
	}
	while (!ft_behind_median(*a, min) && ft_stack_pos(*a, min) > 0)
	{
		*a = ft_stack_reverse_rotate(*a);
		ft_printf("rra\n");
	}
}
