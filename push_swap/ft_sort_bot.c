/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:25 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bot(t_stack **a)
{
	t_node	*node;
	t_node	*new;
	int		max_value;

	max_value = (ft_stack_size(*a) - 1) * 2;
	node = ft_node_new();
	node->a = ft_stack_copy(*a);
	*a = ft_stack_free(*a);
	new = 0;
	while (!ft_node_final(node, max_value))
	{
		ft_generate_nodes(node, &new);
		ft_calculate_value(new);
		//ft_node_display(new);
		node = ft_node_free(node);
		node = new;
		new = 0;
	}
	node = ft_node_free(node);
	//ft_node_display(new);
	//new = ft_node_free(new);
}
/*
	TODO:
		create new Nodes from functions save to new
		add the commands to their commands string
		update their values
		Free node
		node = 0
		Copy good nodes to node
		Free new
		new = 0

*/

void	ft_generate_nodes(t_node *node, t_node **new)
{
	int	i;

	i = 0;
	while (node)
	{
		while (i < 11)
		{
			*new = ft_node_add_front(*new, ft_node_new());
			(*new)->a = ft_stack_copy(node->a);
			(*new)->b = ft_stack_copy(node->b);
			(*new)->commands = ft_strjoin_and_free((*new)->commands, node->commands);
			if (i >= 0 && i <= 2)
				*new = ft_generate_a(*new, i);
			else if (i >= 3 && i <= 5)
				*new = ft_generate_b(*new, i);
			else if (i >= 6 && i <= 8)
				*new = ft_generate_a_and_b(*new, i);
			else if (i >= 9 && i <= 10)
				*new = ft_generate_push(*new, i);
			i++;
		}
		i = 0;
		node = node->next;
	}
}

void	ft_calculate_value(t_node *node)
{
	while (node)
	{
		node->value = ft_stack_value(node->a, node->b);
		node = node->next;
	}
}

char	*ft_strjoin_and_free(char *commands, char *nstr)
{
	char	*temp;

	temp = ft_strjoin(commands, nstr);
	free(commands);
	return (temp);
}
