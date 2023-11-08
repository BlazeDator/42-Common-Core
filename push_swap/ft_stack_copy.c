/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 15:23:00 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_copy(t_stack *stack)
{
	t_stack *new;
	t_stack *start;

	new = 0;
	start = 0;
	if (stack)
	{
		new = ft_stack_new(stack->num);
		// check malloc
		start = new;
		stack = stack->next;
	}
	while (stack)
	{
		new->next = ft_stack_new(stack->num);
		// free others
		new = new->next;
		stack = stack->next;
	}
	if (new)
		new->next = 0;
	return (start);
}
