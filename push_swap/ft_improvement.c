/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_improvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:41 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 10:19:17 by pabernar         ###   ########.fr       */
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

char	*ft_check_sorted(t_queue_node *node)
{
	while (node)
	{
		if (node->base_improvement == node->max_improvement)
			return (ft_strdup(node->commands));
		node = node->next;
	}
	return (0);
}
