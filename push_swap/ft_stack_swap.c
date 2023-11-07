/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 12:09:36 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack **stack, char name)
{
	t_stack	*temp;

	if (ft_stack_size(stack[0]) > 1)
	{
		temp = stack[0];
		stack[0] = stack[0]->next;
		temp->next = stack[0]->next;
		stack[0]->next = temp;
	}
	if (name)
		ft_printf("s%c\n", name);
}
