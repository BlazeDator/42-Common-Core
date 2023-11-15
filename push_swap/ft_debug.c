/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:26:50 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/15 10:40:24 by pabernar         ###   ########.fr       */
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

void	ft_node_display(t_node *traveler)
{
	while (traveler)
	{
		ft_stack_display(traveler->a);
		ft_stack_display(traveler->b);
		ft_printf("Value: %i\n", traveler->value);
		ft_printf("Commands:\n%s", traveler->commands);
		ft_printf("\n");
		traveler = traveler->next;
	}
}

void	ft_node_display_one(t_node *traveler)
{
	ft_stack_display(traveler->a);
	ft_stack_display(traveler->b);
	ft_printf("Value: %i\n", traveler->value);
	ft_printf("Commands:\n%s", traveler->commands);
	ft_printf("\n");
	traveler = traveler->next;
}

