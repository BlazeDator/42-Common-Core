/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:51:42 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 14:26:20 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_swap(t_stack *stack)
{
	t_stack	*temp;

	if (stack && stack->next)
	{
		temp = stack->next;
		stack->next = stack->next->next;
		temp->next = stack;
		return (temp);
	}
	return (stack);
}

t_stack	*ft_stack_rotate(t_stack *stack)
{
	t_stack	*start;
	t_stack	*temp;

	if (stack && stack->next)
	{
		start = stack->next;
		temp = stack;
		while (stack->next)
			stack = stack->next;
		temp->next = 0;
		stack->next = temp;
		return (start);
	}
	return (stack);
}

t_stack	*ft_stack_reverse_rotate(t_stack *stack)
{
	t_stack	*start;

	if (stack && stack->next)
	{
		start = stack;
		while (stack->next->next)
			stack = stack->next;
		stack->next->next = start;
		start = stack->next;
		stack->next = 0;
		return (start);
	}
	return (stack);
}
