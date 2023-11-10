/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:43:01 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 09:02:55 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_queue(t_queue_node *queue)
{
	int	count;

	count = 0;
	if (!queue)
	{
		ft_printf("Queue Node: NULL\n");
		return ;
	}
	while (queue)
	{
		ft_printf("Queue Node %i - %p\n", count, queue);
		ft_printf("Base Improv: %i\n", queue->base_improvement);
		ft_printf("Max Improv: %i\n", queue->max_improvement);
		ft_printf("Commands: \n%s", queue->commands);
		ft_stack_display(queue->a, 'a');
		ft_stack_display(queue->b, 'b');
		ft_printf("Next: %p\n", queue->next);
		ft_printf("------------------------\n");
		queue = queue->next;
		count++;
	}
}

void	ft_queue_size(t_queue_node *queue)
{
	int	count;

	count = 0;
	while (queue)
	{
		count++;
		queue = queue->next;
	}
	ft_printf("Queue Size: %i\n", count);
}
