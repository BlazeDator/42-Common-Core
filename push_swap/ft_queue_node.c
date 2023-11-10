/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:49 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 11:26:38 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue_node *ft_queue_node_new(t_stack *a, t_stack *b, char *commands)
{
	int	base_improvement;
	int	max_improvement;
	t_queue_node *queue;

	base_improvement = ft_stack_calc_improvement(a, b);
	max_improvement = (((ft_stack_size(a) + ft_stack_size(b)) - 1) * 2);
	queue = malloc(sizeof(t_queue_node));
	if (commands)
	{
		commands = ft_strdup(commands);
		if (!commands)
			return (0);
	}
	if (!queue)
		return (0);
	queue->base_improvement = base_improvement;
	queue->max_improvement = max_improvement;
	queue->commands = commands;
	queue->a = ft_stack_copy(a);
	queue->b = ft_stack_copy(b);
	queue->next = 0;
	return (queue);
}

void	ft_queue_node_add_back(t_queue_node **node, t_queue_node *new)
{
	t_queue_node *temp;

	if (node[0])
	{
		temp = node[0];
		while (node[0]->next)
			node[0] = node[0]->next;
		node[0]->next = new;
		node[0] = temp;
	}
	else
		node[0] = new;
}

void	ft_queue_node_add_front(t_queue_node **node, t_queue_node *new)
{
	if (node[0])
		new->next = node[0];
	else
		new->next = 0;
	node[0] = new;
}

void	ft_queue_node_delone(t_queue_node *node)
{
	if (node)
	{
		if (node->a)
			ft_stack_clear(node->a);
		if (node->b)
			ft_stack_clear(node->b);
		if (node->commands)
			free(node->commands);
		free(node);
	}
}

void	ft_queue_node_clear(t_queue_node **node)
{
	t_queue_node	*temp;

	while (node[0])
	{
		temp = node[0]->next;
		ft_queue_node_delone(node[0]);
		node[0] = temp;
	}
}
