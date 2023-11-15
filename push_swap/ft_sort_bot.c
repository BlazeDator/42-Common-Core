/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/15 09:51:51 by pabernar         ###   ########.fr       */
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
		break ;
	}
	//teste
	t_node *traveler = new;
	while (traveler)
	{
		ft_stack_display(traveler->a);
		ft_stack_display(traveler->b);
		ft_printf("Commands:\n%s", traveler->commands);
		ft_printf("\n");	
		traveler = traveler->next;
	}
	//end teste
	node = ft_node_free(node);
	new = ft_node_free(new);
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
