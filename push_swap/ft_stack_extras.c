/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/15 10:14:12 by pabernar         ###   ########.fr       */
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

int	ft_stack_value(t_stack *a, t_stack *b)
{
	int	value;

	value = 0;
	while (a && a->next)
	{
		if (a->number < a->next->number)
			value += 2;
		a = a->next;
	}
	while (b && b->next)
	{
		if (b->number < b->next->number)
			value += 1;
		b = b->next;
	}
	return (value);
}
