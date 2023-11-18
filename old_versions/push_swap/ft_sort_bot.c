/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 09:12:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bot(t_node *node)
{
	t_node	*new;
	int		max_value;

	max_value = ((ft_stack_size(node->a)) * 2);
	new = 0;
	while (!ft_node_final(node, max_value))
	{
		new = ft_generate_nodes(node, new);
		ft_calculate_value(new);
		node = ft_node_free(node);
		node = ft_value(new);
		new = ft_node_free(new);
	}
	node = ft_node_free(node);
}
/*
	TODO:
	Function is creating a node everytime I ignore number 11 
	because I dont have an if condition for the useless
	Divide it in 2, maybe: 
	the creation of the new node + the generation of the differences
*/

t_node	*ft_value(t_node *node)
{
	t_node	*new;
	int		value;

	value = 0;
	new = 0;
	value = ft_max_value(node);
	while (node)
	{
		if (node->value >= (value - 2) && ft_check_duplicates(node, new))
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

void	ft_calculate_value(t_node *node)
{
	while (node)
	{
		node->value = ft_stack_value(node->a, node->b);
		node = node->next;
	}
}

char	*ft_strjoin_f(char *commands, char *nstr)
{
	char	*temp;

	temp = ft_strjoin(commands, nstr);
	free(commands);
	return (temp);
}
