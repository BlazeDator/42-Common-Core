/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/14 10:56:00 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bot(t_stack **a, t_stack **b)
{
	t_node	*node;

	if (a && b)
		ft_printf("I'm Sort BOT, beep boop!\n");
	node = ft_node_new();
	node->a = ft_stack_copy(*a);
	ft_printf("Node stack a:\n");
	ft_stack_display(node->a);
	ft_printf("\n\nOriginal stack a:\n");
	ft_stack_display(*a);
	node = ft_node_free(node);
	*a = ft_stack_free(*a);
	ft_printf("node: %p , stack a: %p\n", node, *a);
}
