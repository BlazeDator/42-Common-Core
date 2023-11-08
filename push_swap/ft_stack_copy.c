/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 12:42:04 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_copy(t_stack *stack)
{
	t_stack *new;
	t_stack *start;

	if (stack)
	{
		new = ft_stack_new(stack->num);
		start = new;
		stack = stack->next;
	}
	while (stack)
	{
		new->next = ft_stack_new(stack->num);
		new = new->next;
		stack = stack->next;
	}
	new->next = 0;
	return (start);
}
