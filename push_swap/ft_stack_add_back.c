/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:39 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 10:14:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack[0])
	{
		temp = stack[0];
		while (stack[0]->next)
			stack[0] = stack[0]->next;
		stack[0]->next = new;
		stack[0] = temp;
	}
	else
		stack[0] = new;
}
