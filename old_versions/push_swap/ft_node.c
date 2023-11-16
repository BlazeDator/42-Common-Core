/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:19:42 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/16 09:19:25 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = 0;
	new->last_c = -1;
	new->commands = malloc(1);
	if (!new->commands)
	{
		free(new);
		return (0);
	}
	new->commands[0] = '\0';
	new->a = 0;
	new->b = 0;
	new->next = 0;
	return (new);
}

t_node	*ft_node_add_back(t_node *node, t_node *new)
{
	t_node	*start;

	start = 0;
	if (node && new)
	{
		start = node;
		while (node->next)
			node = node->next;
		node->next = new;
		return (start);
	}
	else if (new)
		return (new);
	return (0);
}

t_node	*ft_node_add_front(t_node *node, t_node *new)
{
	if (node && new)
	{
		new->next = node;
		return (new);
	}
	else if (new)
		return (new);
	return (0);
}

t_node	*ft_node_free(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node->commands);
		node->commands = 0;
		node->a = ft_stack_free(node->a);
		node->b = ft_stack_free(node->b);
		free(node);
		node = temp;
	}
	return (0);
}
