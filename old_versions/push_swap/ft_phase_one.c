/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:40:01 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 12:16:31 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_phase_one(t_node *node)
{
	if (ft_stack_size(node->a) > 3)
	{
		node = ft_generate_push(node, 10);
		node = ft_generate_push(node, 10);
	}
	if (ft_stack_size(node->a) > 3)
		node = ft_bot_one(node);
	return (node);	
}

t_node	*ft_bot_one(t_node *node)
{
	t_node	*new;

	new = 0;
	while (!new)
	{
		new = ft_generate_nodes(node, new);
		ft_phase_one_calc_value(new);
		node = ft_node_free(node);
		node = ft_phase_one_valuables(new);
		new = ft_node_free(new);
		new = ft_phase_one_final(node);
	}
	node = ft_node_free(node);
	return (new);
}

t_node	*ft_phase_one_final(t_node *node)
{
	t_node	*new;

	new = 0;
	while (node)
	{
		if (ft_stack_size(node->a) <= 3)
		{
			new = ft_stack_to_node(node->a, node->b);
			new->commands = ft_strjoin_f(new->commands, node->commands);	
			return (new);
		}	
		node = node->next;
	}
	return (0);
}

void	ft_phase_one_calc_value(t_node *node)
{
	while (node)
	{
		node->value = ft_phase_one_stacks_value(node->a, node->b);
		node = node->next;
	}
}

t_node	*ft_phase_one_valuables(t_node *node)
{
	t_node	*new;
	int		value;

	value = 0;
	new = 0;
	value = ft_max_value(node);
	while (node)
	{
		if (node->value >= (value - 1) && ft_check_duplicates(node, new))
		{
			new = ft_node_add_front(new, ft_node_new());
			new->a = ft_stack_copy(node->a);
			new->b = ft_stack_copy(node->b);
			new->commands = ft_strjoin_f(new->commands, node->commands);
			new->value = node->value;
		}
		node = node->next;
	}
	return (new);
}
