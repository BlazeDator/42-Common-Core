/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:53:04 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 17:33:10 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_phase_two_sa(t_stack **a);

void	ft_phase_two(t_stack **a)
{
	if (ft_stack_sorted(*a))
		return ;
	if (ft_stack_size(*a) == 2)
	{
		*a = ft_stack_swap(*a);
		ft_printf("sa\n");
		return ;
	}
	ft_phase_two_sa(a);
	if (ft_stack_sorted(*a))
		return ;
	if ((*a)->number < (*a)->next->number
		&& (*a)->number > (*a)->next->next->number
		&& (*a)->next->number > (*a)->next->next->number)
	{
		*a = ft_stack_reverse_rotate(*a);
		ft_printf("rra\n");
	}
	else if ((*a)->number > (*a)->next->number
		&& (*a)->number > (*a)->next->next->number
		&& (*a)->next->number < (*a)->next->next->number)
	{
		*a = ft_stack_rotate(*a);
		ft_printf("ra\n");
	}
}

static void	ft_phase_two_sa(t_stack **a)
{
	if ((*a)->number > (*a)->next->number
		&& (*a)->number > (*a)->next->next->number
		&& (*a)->next->number > (*a)->next->next->number)
	{
		*a = ft_stack_swap(*a);
		ft_printf("sa\n");
	}
	else if ((*a)->number < (*a)->next->number
		&& (*a)->number < (*a)->next->next->number
		&& (*a)->next->number > (*a)->next->next->number)
	{
		*a = ft_stack_swap(*a);
		ft_printf("sa\n");
	}
	else if ((*a)->number > (*a)->next->number
		&& (*a)->number < (*a)->next->next->number
		&& (*a)->next->number < (*a)->next->next->number)
	{
		*a = ft_stack_swap(*a);
		ft_printf("sa\n");
	}
}
