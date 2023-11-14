/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/14 10:40:47 by pabernar         ###   ########.fr       */
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
