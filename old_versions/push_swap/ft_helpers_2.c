/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 10:20:02 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_copy(t_stack *stack)
{
	t_stack	*new;

	new = 0;
	while (stack)
	{
		new = ft_stack_add_back(new, ft_stack_new(stack->number));
		stack = stack->next;
	}
	return (new);
}
/*
	if (b && ft_stack_size(b))
		value += 2;
*/

int	ft_stack_value(t_stack *a, t_stack *b)
{
	int	value;
	int	temp;

	value = 0;
	if (a)
		temp = a->number;
	while (a && a->next)
	{
		if (a->number < a->next->number)
			value += 2;
		a = a->next;
	}
	if (a && a->number > temp)
		value += 2;
	while (b && b->next)
	{
		if (b->number > b->next->number)
			value += 1;
		b = b->next;
	}
	return (value);
}

int	ft_max_value(t_node *traveler)
{
	int	value;

	value = 0;
	while (traveler)
	{
		if (traveler->value > value)
			value = traveler->value;
		traveler = traveler->next;
	}
	return (value);
}

int	ft_check_duplicates(t_node *node, t_node *new)
{
	while (new)
	{
		if (ft_stack_identical(node->a, new->a) 
			&& ft_stack_identical(node->b, new->b))
			return (0);
		new = new->next;
	}
	return (1);
}

int	ft_stack_identical(t_stack *stack, t_stack *copies)
{
	int	identical;

	identical = 1;
	while (stack && copies)
	{
		if (stack->number != copies->number)
		{
			identical = 0;
			break ;
		}
		stack = stack->next;
		copies = copies->next;
	}
	return (identical);
}
