/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:16:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/16 09:19:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_generate_a(t_node *node, int i)
{
	char	*temp;

	temp = 0;
	if (i == 0)
	{
		node->a = ft_stack_swap(node->a);
		temp = ft_strjoin(node->commands, "sa\n");
	}
	else if (i == 1)
	{
		node->a = ft_stack_rotate(node->a);
		temp = ft_strjoin(node->commands, "ra\n");
	}
	else if (i == 2)
	{
		node->a = ft_stack_reverse_rotate(node->a);
		temp = ft_strjoin(node->commands, "rra\n");
	}
	node->last_c = i;
	free(node->commands);
	node->commands = temp;
	return (node);
}

t_node	*ft_generate_b(t_node *node, int i)
{
	char	*temp;

	temp = 0;
	if (i == 3)
	{
		node->b = ft_stack_swap(node->b);
		temp = ft_strjoin(node->commands, "sb\n");
	}
	else if (i == 4)
	{
		node->b = ft_stack_rotate(node->b);
		temp = ft_strjoin(node->commands, "rb\n");
	}
	else if (i == 5)
	{
		node->b = ft_stack_reverse_rotate(node->b);
		temp = ft_strjoin(node->commands, "rrb\n");
	}
	node->last_c = i;
	free(node->commands);
	node->commands = temp;
	return (node);
}

t_node	*ft_generate_a_and_b(t_node *node, int i)
{
	char	*temp;

	temp = 0;
	if (i == 6)
	{
		node->a = ft_stack_swap(node->a);
		node->b = ft_stack_swap(node->b);
		temp = ft_strjoin(node->commands, "ss\n");
	}
	else if (i == 7)
	{
		node->a = ft_stack_rotate(node->a);
		node->b = ft_stack_rotate(node->b);
		temp = ft_strjoin(node->commands, "rr\n");
	}
	else if (i == 8)
	{
		node->a = ft_stack_reverse_rotate(node->a);
		node->b = ft_stack_reverse_rotate(node->b);
		temp = ft_strjoin(node->commands, "rrr\n");
	}
	node->last_c = i;
	free(node->commands);
	node->commands = temp;
	return (node);
}

t_node	*ft_generate_push(t_node *node, int i)
{
	char	*temp;

	temp = 0;
	if (i == 9)
	{
		ft_stack_push(&node->a, &node->b);
		temp = ft_strjoin(node->commands, "pa\n");
	}
	else if (i == 10)
	{
		ft_stack_push(&node->b, &node->a);
		temp = ft_strjoin(node->commands, "pb\n");
	}
	node->last_c = i;
	free(node->commands);
	node->commands = temp;
	return (node);
}
