/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_improvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:41 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 12:46:22 by pabernar         ###   ########.fr       */
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

char	*ft_check_sorted(t_queue_node *node)
{
	while (node)
	{
		if (node->base_improvement == node->max_improvement)
		{
			if (node->commands)
				return (ft_strdup(node->commands));
			else
				return (ft_strdup(""));
		}
		node = node->next;
	}
	return (0);
}

void	ft_update_commands(t_queue_node *queue)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (queue->commands && queue->commands[0])
		{
			free(queue->commands);
			queue->commands = 0;
		}
		i++;
		queue = queue->next;
	}
}

void	ft_update_improvement(t_queue_node *queue)
{
	int	improvement;

	improvement = 0;
	while (queue)
	{
		improvement = ft_stack_calc_improvement(queue->a, queue->b);
		//ft_printf("IMPROVEMENT: %i\n", improvement);
		queue->base_improvement = improvement;
		queue = queue->next;
	}
}

void	ft_clean_improvement(t_queue_node **queue)
{
	t_queue_node *start;
	t_queue_node *temp;
	int	improvement;

	improvement = 0;
	start = queue[0];
	while (queue[0])
	{
		if (queue[0]->base_improvement > improvement)
			improvement = queue[0]->base_improvement;
		queue[0] = queue[0]->next;
	}
	queue[0] = start;
	while (queue[0]->base_improvement < improvement)
	{
		temp = queue[0];
		queue[0] = queue[0]->next;
		ft_queue_node_delone(temp);
	}
	start = queue[0];
	while (queue[0] && queue[0]->next)
	{
		if (queue[0]->next->base_improvement < improvement)
		{
			temp = queue[0]->next;
			queue[0]->next = queue[0]->next->next;
			ft_queue_node_delone(temp);
		}
		else
			queue[0] = queue[0]->next;
	}
	queue[0] = start;
}
