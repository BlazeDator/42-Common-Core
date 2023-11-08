/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:49 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 15:13:42 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue_node *ft_queue_node_new(t_stack *a, t_stack *b)
{
	char	*commands;
	int	base_improvement;
	int	max_improvement;
	t_queue_node *queue;

	base_improvement = ft_stack_calc_improvement(a, b);
	max_improvement = ((ft_stack_size(a) - 1) * 2);
	queue = malloc(sizeof(t_queue_node));
	commands = malloc(1);
	if (!commands || !queue)
		return (0);
	commands[0] = '\0';
	queue->base_improvement = base_improvement;
	queue->max_improvement = max_improvement;
	queue->commands = commands;
	queue->a = ft_stack_copy(a);
	queue->b = ft_stack_copy(b);
	queue->next = 0;
	return (queue);
}

void	ft_queue_node_delone(t_queue_node *node)
{
	if (node)
	{
		ft_stack_clear(node->a);
		ft_stack_clear(node->b);
		free(node->commands);
		free(node);
	}
}

void	ft_queue_node_clear(t_queue_node *node)
{
	t_queue_node	*temp;

	while (node)
	{
		temp = node->next;
		ft_queue_node_delone(node);
		node = temp;
	}
}
