/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:04:21 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 09:11:22 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_generate_nodes(t_node *node, t_node *new)
{
	int	i;

	while (node)
	{
		i = 0;
		while (i < 11)
		{
			if (!ft_check_useless(node, i))
			{
				new = ft_node_add_front(new, ft_node_new());
				new->a = ft_stack_copy(node->a);
				new->b = ft_stack_copy(node->b);
				new->commands = ft_strjoin_f(new->commands, node->commands);
				new = ft_generate_selector(new, i);
			}
			i++;
		}
		node = node->next;
	}
	return (new);
}

t_node	*ft_generate_selector(t_node *new, int i)
{
	if (i >= 0 && i <= 2)
		new = ft_generate_a(new, i);
	else if (i >= 3 && i <= 5)
		new = ft_generate_b(new, i);
	else if (i >= 6 && i <= 8)
		new = ft_generate_a_and_b(new, i);
	else if (i >= 9 && i <= 10)
		new = ft_generate_push(new, i);
	return (new);
}
