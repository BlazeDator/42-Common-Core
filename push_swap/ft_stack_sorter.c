/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 10:49:40 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_generate_possibilities(t_queue_node *queue, t_queue_node **new_queue)
{
	t_queue_node	*start;
	int	i;

	// TODO: generate all the copies first then use functions on each
	ft_queue_node_add_back(new_queue, ft_queue_node_new(queue->a, queue->b, queue->commands));
	start = new_queue[0];
	queue->commands = ft_strjoin_free(queue->commands, ft_swap(queue->a, "sa\n"));
	









	new_queue = start;
}

char	*ft_stack_sorter(t_stack **a, t_stack **b)
{
	t_queue_node *queue;
	t_queue_node *new_queue;
	t_queue_node *start;
	char	*commands;

	commands = 0;	
	queue = ft_queue_node_new(a[0], b[0], "");
	while (!commands)
	{
		start = queue;
		commands = ft_check_sorted(queue);
		if (commands)
			break ;
		while (queue)
		{
			// create new queue?
			// Consider doing the loop inside the following function for less lines
			// Would need to send the current queue pointer address
			ft_generate_possibilities(queue, &new_queue) 
			queue = queue->next;
		}
		// delete old ones
		// delete undesirables from new queue
		// point to new queue
	}
	ft_queue_node_clear(start);
	return (commands);
}
