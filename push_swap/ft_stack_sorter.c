/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 13:14:34 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_calc_improvement(t_stack *a, t_stack *b)
{
	int	improvement;

	improvement = 0;
	while (a && a->next)
	{
		if (a->num < a->next->num)
			improvement += 2;
		a = a->next;
	}
	while (b && b->next)
	{
		if (b->num < b->next->num)
			improvement += 1;
		b = b->next;
	}
	return (improvement);
}
/*
	base_improvement = ft_stack_calc_improvement(a[0], b[0]);
	To calculate the max improvement:
	max_improvement = ((ft_stack_size(a[0]) - 1) * 2);
*/

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

char	*ft_stack_sorter(t_stack **a, t_stack **b)
{
	t_queue_node *queue;

	queue = ft_queue_node_new(a[0], b[0]);
	ft_printf("Queue Node:\n");
	ft_stack_display(queue->a, 'a');
	ft_stack_display(queue->b, 'b');
	return ("teste");
}
