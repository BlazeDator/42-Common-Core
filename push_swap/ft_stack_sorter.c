/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 15:15:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_calc_improvement(t_stack *a, t_stack *b)
{
	int	improvement;

	improvement = 0;
	while (a && a->next)
	{
		if (a->num < a->next->num)
			improvement += 2;
		a = a->next;
	}
	while (b && b->next)
	{
		if (b->num < b->next->num)
			improvement += 1;
		b = b->next;
	}
	return (improvement);
}

char	*ft_stack_sorter(t_stack **a, t_stack **b)
{
	t_queue_node *queue;
	//t_queue_node *start;

	queue = ft_queue_node_new(a[0], b[0]);
	queue->next = ft_queue_node_new(a[0], b[0]);
	ft_queue_node_clear(queue);
	return ("teste");
}
