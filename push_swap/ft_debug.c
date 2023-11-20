/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:26:50 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/20 10:41:54 by pabernar         ###   ########.fr       */
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
		ft_printf("( %i )->", stack->number);
		count++;
		stack = stack->next;
	}
	ft_printf("%p Total: %i", stack, count);
	ft_printf("\n");
}

void	ft_targets_display(t_stack *stack)
{
	ft_printf("Targets: \n");
	while (stack)
	{
		ft_printf("( %i )\t-tar->\t( %i )\n", stack->number, stack->target);
		ft_printf("Push_cost: %i", stack->push_cost);
		ft_printf("\n");
		stack = stack->next;
	}
	ft_printf("\n");
}
