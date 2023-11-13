/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:26:50 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 11:53:09 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_display(t_stack *stack)
{
	int	count;

	count = 0;
	ft_printf("Stack: ");
	while (stack)
	{
		ft_printf("( %i )->", count, stack->number);
		count++;
		stack = stack->next;
	}
	ft_printf("(END) Total:%i", count);
	ft_printf("\n");
}
