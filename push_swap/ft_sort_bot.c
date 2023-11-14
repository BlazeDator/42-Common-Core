/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/14 12:55:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bot(t_stack **a)
{
	t_node	*node;
	int		max_value;

	max_value = (ft_stack_size(*a) - 1) * 2;
	node = ft_node_new();
	node->a = ft_stack_copy(*a);
	*a = ft_stack_free(*a);
	while (!ft_node_final(node, max_value))
	{

	}
	node = ft_node_free(node);
}
